/*
 * dbkbd.c
 *
 *  Created on: Feb 10, 2019
 *      Author: pho
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <linux/input.h>
#include <fcntl.h>
#include <xdo.h>
#include <signal.h>
#include "keytables.h"
#include "special.h"

#define EV_MAKE 1
#define EV_BREAK 0
#define EV_REPEAT 2

int alive = 1;

void send_data(xdo_t *x, wchar_t *data, Window *wins, int offset);
wchar_t *process_chars(unsigned short scan_code, bool shift, bool ctrl);
char **get_devices();
void get_window(xdo_t *x, Window *wind, int timeout);

void signalHandler(int signum)
{
	printf("Interrupt signal %d received.\n", signum);
	printf("Sending shutdown...\n");
	alive = 0;
}

int main(int argc, char **argv)
{
	if (signal(SIGINT, signalHandler) == SIG_ERR)
		printf("Couldn't register interrupt handler.\n");

	xdo_t *x = xdo_new(NULL);

	Window this;
	get_window(x, &this, 0);

	char **kbd_devices = get_devices();
	int kbd_len = 0;
	while (**(kbd_devices + kbd_len))
		printf("device: %s\n", *(kbd_devices + (kbd_len++)));

	if (kbd_len < 2) {
		printf("Only one keyboard detected.  Exiting.\n");
		exit(1);
	}

	Window *wins = malloc(sizeof(Window) * kbd_len);
	if (wins == NULL) {
		// Design decision to rely on OS to reclaim mallocated memory
		printf("Could not allocate memory for wins\n");
		exit(8);
	}
	for (int i = 0; i < kbd_len; ++i) {
		printf("YOU HAVE 5 SECONDS TO CHANGE TO TARGET WINDOW #%d.\n", i + 1);
		get_window(x, wins + i, 5);
	}

	// CREATE FILE DESCRIPTORS
	int *kbd_handles = malloc(sizeof(kbd_handles) * kbd_len);
	if (kbd_handles == NULL) {
		printf("Could not allocate memory for kbd_handles\n");
		exit(8);
	}

	for (int i = 0; i < kbd_len; ++i) {
		char *name = malloc(
				strlen("/dev/input/") + strlen(*(kbd_devices + i)) + 1);
		if (name == NULL) {
			printf("Could not allocate memory for name\n");
			exit(7);
		}
		strcpy(name, "/dev/input/");
		strcat(name, *(kbd_devices + i));
		printf("Opening %s file descriptor...", name);
		*(kbd_handles + i) = open(name, O_RDONLY);
		if (*kbd_handles + i == -1) {
			printf("Error opening %s.\nAre you root?\n", name);
			exit(89);
		}
		printf("Successful.\n");
		free(name);
	}

	// make list of xdo annoyances
	populate_list_special();

	unsigned short scan_code = 0;
	struct input_event event;
	bool *shift = malloc(sizeof(bool) * kbd_len);
	bool *ctrl = malloc(sizeof(bool) * kbd_len);
	if (shift == NULL || ctrl == NULL) {
		printf("Could not allocate memory for either shift or ctrl\n");
		exit(6);
	}

	for (int i = 0; i < kbd_len; ++i) {
		*(shift + i) = false;
		*(ctrl + i) = false;
	}

	// Disable blocking read() for all keyboard event FDs
	for (int i = 0; i < kbd_len; ++i) {
		int flags = fcntl(*(kbd_handles + i), F_GETFL, 0);
		fcntl(*(kbd_handles + i), F_SETFL, flags | O_NONBLOCK);
	}

	int offset = 0;
	while (alive) {
		if (read(*(kbd_handles + offset), &event, sizeof(struct input_event))
				> 0) {

			if (event.type != EV_KEY) // always ev_key
				continue;

			scan_code = event.code;

			if (scan_code >= sizeof(char_or_func)) // OOR
				continue;

			// EV_MAKE = pressed
			if (event.value == EV_MAKE) {
				if (scan_code == KEY_LEFTSHIFT || scan_code == KEY_RIGHTSHIFT)
					*(shift + offset) = true;
				else if (scan_code == KEY_LEFTCTRL || scan_code == KEY_RIGHTCTRL)
					*(ctrl + offset) = true;

				wchar_t *wch = process_chars(scan_code, *(shift + offset),
						*(ctrl + offset));

				// SEND TO WINDOW A SINGLY-PRESSED KEY
				if (*wch != L'\0')
					send_data(x, wch, wins, offset);

				free(wch);
			}

			// EV_BREAK = released
			if (event.value == EV_BREAK) {
				if (scan_code == KEY_LEFTSHIFT || scan_code == KEY_RIGHTSHIFT)
					*(shift + offset) = false;
				else if (scan_code == KEY_LEFTCTRL || scan_code == KEY_RIGHTCTRL)
					*(ctrl + offset) = false;
			}

			if (event.value == EV_REPEAT) {
				wchar_t *wch = process_chars(scan_code, *(shift + offset),
						*(ctrl + offset));
				if (*wch != L'\0')
					send_data(x, wch, wins, offset);

				free(wch);
			}

		}

		offset = (offset == kbd_len - 1) ? 0 : offset + 1;
		usleep(10000); // 10000us = 10ms
	}

	printf("Freeing allocated memory...");
	for (int i = 0; i < 10; ++i)
		free(*(kbd_devices + i));
	free(kbd_devices);
	free(kbd_handles);
	free(wins);
	free(x);
	printf("Done.\nGoodbye\n");

	exit(0);
}

void send_data(xdo_t *x, wchar_t *data, Window *wins, int offset)
{
	fprintf(stdout, "KBD %d: %ls\n", offset, data);
	fflush(stdout);

	// Let's not run this as root...
	setegid(65534);
	seteuid(65534);

	char *keysequence = malloc(20);
	if (keysequence == NULL) {
		printf("Could not allocate memory for keysequence\n");
		exit(5);
	}
	sprintf(keysequence, "%ls", data);

	xdo_send_keysequence_window(x, *(wins + offset), keysequence, 0);

	free(keysequence);

	// Restore root privileges for file access
	setegid(0);
	seteuid(0);
}

wchar_t *process_chars(unsigned short scan_code, bool shift, bool ctrl)
{
	wchar_t *wch = malloc(256 * sizeof(wchar_t));  // caller must free()
	if (wch == NULL) {
		printf("Could not allocate memory for wch\n");
		exit(4);
	}

	// TODO: improve lookup
	if (is_xdo_unfriendly(scan_code)) {
		if (!shift) {
			const char *name = get_char_name(scan_code);
			swprintf(wch, ctrl ? strlen(name) + 10 : strlen(name) + 1,
					ctrl ? L"Control+%s" : L"%s", name);
		} else {
			const char *name = get_shift_name(scan_code);
			swprintf(wch, strlen(name) + 1, L"%s", name);
		}
	}

	else if (is_char_key(scan_code)) {
		if (!shift) {
			swprintf(wch, ctrl ? 10 : 2, ctrl ? L"Control+%lc" : L"%lc",
					char_keys[to_char_keys_index(scan_code)]);
		} else {
			swprintf(wch, 2, L"%lc", shift_keys[to_char_keys_index(scan_code)]);
		}
	}

	else if (is_func_key(scan_code)) {
		int len = wcslen(wch);
		if (scan_code == KEY_SPACE) {
			swprintf(wch, len + 6, L"space");
		} else if (scan_code == KEY_TAB) {
			swprintf(wch, len + 4, L"Tab");
		} else if (scan_code == KEY_BACKSPACE) {
			swprintf(wch, len + 10, L"BackSpace");
		} else if (scan_code == KEY_DELETE) {
			swprintf(wch, len + 10, L"Delete");
		}
	}

	return wch;
}

char **get_devices()
{
	// grab USB keyboard devices
	char *command =
			"grep -E 'Handlers|EV=' /proc/bus/input/devices | grep -B1 'EV=120013' | grep -Eo 'event[0-9]+'";
	FILE *grep_devices_p = popen(command, "r");

	char **kbd_devices_s = malloc(10 * sizeof(char *)); // up to 10 keyboards(!!!)
	if (kbd_devices_s == NULL) {
		printf("Could not allocate memory for kbd_devices_s.\n");
		exit(2);
	}
	for (int i = 0; i < 10; ++i) {
		*(kbd_devices_s + i) = malloc(9 * sizeof(char)); // "eventXX\n" + '\0'
		if(*(kbd_devices_s + i) == NULL) {
			printf("Could not allocate memory for *kbd_devices + %d", i);
			exit(3);
		}
		**(kbd_devices_s+i) = '\0';
	}

	// stops at '\n', should be 'eventX\n' or 'eventXX\n' ==> 8 chars + '\0'
	for (int i = 0; NULL != (fgets(*(kbd_devices_s + i), 9, grep_devices_p))
			&& i < 10; ++i) {
		// remove the '\n' from fgets()
		*(*(kbd_devices_s + i) + strlen(*(kbd_devices_s + i)) - 1) = '\0';
	}

	pclose(grep_devices_p);
	return kbd_devices_s;
}

void get_window(xdo_t *x, Window *wind, int timeout)
{
	if (timeout) {
		sleep(timeout);
	}
	xdo_get_active_window(x, wind);
}
