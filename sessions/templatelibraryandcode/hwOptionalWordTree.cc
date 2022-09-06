#include <iostream>
#include <map>
using namespace std;

class WordTree {
private:
	struct Node {
		map<string, Node*> next;
		uint32_t count;
		Node() { count = 1; }
	};
	Node root;
public:
	WordTree() {}
	int skipSpace(const char words[], int start) {
		while (words[start] == ' ') // keep going as long as there are spaces
			start++;
		return start;
	}

	void print(const char words[], int start, int end) {
		for (int i = start; i < end; i++)
			cout << words[i];
		cout << '\n';
	}
	void readWords(const char words[]) {
		int start = skipSpace(words, 0);
		int end;
		Node* p = &root;
		for (end = start+1; words[end] != '\0'; end++)
			if (words[end] <= ' ') {
				print(words, start, end);
				string s(&words[start], end-start);
				p->next[s] = new Node(); //create a new node for all the words following this one
				p = p->next[s]; // p now points to the next word node
				start = skipSpace(words, end+1);
				// at this point, should be guaranteed that words[start] is the next word
				end = start;
			}
	}
	friend ostream& operator <<(ostream& s, const WordTree& w) {
		for (const auto& a : w.root.next) {
			s << a.first << ' ';
		}
		s << ' ';
		return s;
	}
};

int main() {
	const char words[] = "   hello    this is  a test";
	const char words2[] = "hello there welcome to C++";
	const char words3[] = "testing testing 123";
	WordTree wordTree;
	wordTree.readWords(words);
	wordTree.readWords(words2);
	wordTree.readWords(words3);
	cout << wordTree;
/*
	hello this is a test
	test
	this
	what

 */
}
