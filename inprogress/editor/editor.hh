#pragma once
#include <string>

class editor {
private:
	std::string text; // bad implementation, a single huge string
	uint64_t cursor;
public:
	editor();
	~editor();
	editor(const editor& orig) = delete;
	editor& operator =(const editor& orig) = delete;
	void open(const char filename[]);
	void save(const char filename[]);
	void gotopos(uint64_t pos);
	void gotostart() { gotopos(0); }
	void gotoend() { gotopos(text.length()-1); }
	void pageup();
	void pagedown();

	// display the current page
	void display();

	// insert a string at the cursor position
	void insert(uint64_t pos, const char s[], uint32_t len);
	void mainloop();
};
