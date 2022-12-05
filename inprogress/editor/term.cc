#include <unistd.h>
#include <stdio.h>
#include <termios.h>

using namespace std;
static struct termios old_terminal_settings;

void setterm() {
  tcgetattr(STDIN_FILENO, &old_terminal_settings);

  // Set terminal to unbuffered input mode
  struct termios new_terminal_settings = old_terminal_settings;
  new_terminal_settings.c_lflag &= ~ICANON;
  tcsetattr(STDIN_FILENO, TCSANOW, &new_terminal_settings);
}

void resetterm() {
  // Restore the original terminal settings
  tcsetattr(STDIN_FILENO, TCSANOW, &old_terminal_settings);

}

int main() {
  int c;
  while (c = getc(stdin)) {
    putc(c, stdout);
  }
  return 0;
}