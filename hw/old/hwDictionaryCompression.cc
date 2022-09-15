int main() {
	ifstream f("words.txt");
	/*
		read in the dictionary.
		find out the length of the file and dynamically allocate a single block of memory the size of the entire file.
		https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring

		this will contain the following letters:

		aa\naah\n...

		remove all spaces and \n and create a compressed file where the last letter of each word has the high bit set:

		a\225aa\252

		in the above case, 'a' + 128 = 97+128 = 225 and 'h' + 128 = 104+128 = 252

		Write the resulting block of memory (which is smaller) out to a binary file http://www.cplusplus.com/doc/tutorial/files/

		**** Don't forget to deallocate the memory you allocated
	
	*/
	ofstream out("compresseddict.ser", ios::binary);
}	
