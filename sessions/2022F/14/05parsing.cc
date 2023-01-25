#include <regex>
#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;
void handle_doc(const char* p, uint32_t len) {
  cout << p << " " << len << '\n';
}

void handle_quiz(const char* p, uint32_t len) {

}

void handle_q(const char* p, uint32_t len) {

}

void handle_table(const char* p, uint32_t len) {

}



int main() {
    ifstream f("example.md");
    unordered_map<string, PointerToHandler> handler_map = {
        {"doc", handle_doc},
        {"quiz", handle_quiz}
    };
  regex idoc("%(doc|quiz|q|table)\((.*)\)");
    cmatch m;
    char buf[4096];
    while (f.getline(buf, sizeof(buf))) {
      if (regex_search(buf, m, idoc)) {
        string_view tag(buf+m.position(1), m.length(1));
        //TODO: this will crash. Fix it for 100 hw points
        handler_map[tag](buf + m.position(1), m.length(1));
      }

    }

}