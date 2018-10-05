#pragma once

class TextBuffer {
private:
	std::vector<std::string> lines;
public:
	TextBuffer();

	// open the named file and read each line to the textbuffer
	TextBuffer(const char filename[]);

	class Cursor {
	public:
		Cursor(uint32_t linenum, uint32_t col) {}
	};

	TextBuffer cut(const Cursor& start, const Cursor& end);
	void paste(const Cursor& start, const TextBuffer& b);
	void insert(const Cursor& cursor, const string& s);

	// if count == 0, replace all in the buffer
	void replace(const string& search, const string& replace, int count);

	// save as search except the text to be searched is a regular expression pattern
	void replaceregex(const string& pattern, const string& replace, int count);
	void setMark(Cursor& c);
};
