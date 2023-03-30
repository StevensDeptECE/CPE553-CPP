#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

#include "text_win.hh"

class editor {
private:
	text_win w;
	uint32_t rows,cols;
	std::string text; // bad implementation, a single huge string
	uint64_t cursor;
	uint32_t page_size;
	// color of text entry field for search/replace, entering filenames, etc.
	uint32_t field_fg, field_bg;
	typedef bool (editor::*action)();
	std::vector<action> action_map;  // map action numbers to methods
	std::vector<uint32_t> input_map; // map input to actions
public:
	editor(int rows, int cols);
	editor();
	~editor();
	editor(const editor& orig) = delete;
	editor& operator =(const editor& orig) = delete;

	void bind(uint32_t input_event, action);
	void load(const char filename[]);
	void save(const char filename[]);
	void gotopos(uint64_t pos);
	bool gotostart();
	bool gotoend();
	bool startofline();
	bool endofline();
	bool forward();
	bool backward();
	bool nextline();
	bool prevline();
	bool setmark();
	bool cut();
	bool paste();
	bool abort();
	bool compile();
	bool undo();
	bool redo();
	bool repeat();
	
	bool pageup();
	bool pagedown();
	bool search_next();
	bool search_prev();

	bool replace_next();
	bool replace_all();

	void field() { w.field(field_fg, field_bg, rows-1,0, cols);}

	void display();	   // display the current page

	// insert a string at the cursor position
	void insert(uint64_t pos, const char s[], uint32_t len);
	void mainloop();
};
