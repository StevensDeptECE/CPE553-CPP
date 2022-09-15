#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <map>
#include "String.hh"

inline bool readFileCompletely(const String& filename, char*& buf, size_t& len) {
  char fileName[80];
  filename.tocstr(fileName, 80);
  
  int fh = open(fileName, O_RDONLY);
  if (fh < 0) {
    return false;
  }

  struct stat info;
  fstat(fh, &info);
  buf = new char[info.st_size];
  len = info.st_size;
  size_t bytesRead = read(fh, buf, len);
  close(fh);
  return (bytesRead == len); // if same length, all is well
}


class Config {
private:

  class Data {  };

  class IntData : public Data {
  private:
    int val;
  public:
    IntData(int val_) : val(val_) {}
  };
  class FloatData : public Data {
  private:
    float val;
  public:
    FloatData(float val_) : val(val_) {}
  };
  class DoubleData : public Data {
  private:
    double val;
  public:
    DoubleData(double val_) : val(val_) {}
  };
  class StringData : public Data {
  private:
    String val;
  public:
    StringData(const String& val_) : val(val_) {}
  };

  map<String,Data*> objects;

public:
  Config() {}
  void add(const String& name, int val) { objects[name] = new IntData(val);  }
  void add(const String& name, float val) { objects[name] = new FloatData(val);  }
  void add(const String& name, double val) { objects[name] = new DoubleData(val);  }
};


/*
  Read in an object config file
  Individual objects are introduced with the define keyword
  attributes are on a single line each in name value format
  files may be included with:
     include file
  Each object ends when a new object is defined (possibly add end for recursively defined object structure?
*/
class ConfigFile {
private:
  map<String, Config*> objects;
  char* buf;
  size_t len;

  class Action {
  protected:
    ConfigFile& f;
    String name;
  public:
    Action(ConfigFile& f_, String name_) : f(f_), name(name_) {}
    virtual void operator()(int lineNum, const char* p) const = 0;
  };

  class Def : public Action {
  public:
    Def(ConfigFile& f, const String& name) : Action(f, name) {
      
    }
    void operator()(int lineNum, const char* p) const {
      String className = getToken(p);
      f.objects[className] = new Config();
    };
  };

  class Include : public Action {
  public:
    Include(ConfigFile& f, const String& name) : Action(f, name) {
      
    }
    void operator()(int lineNum, const char* p) const {
      const char* start = p;
      endLine(p);
      String filename(start, p-start);
      cerr << "include file" << filename;
      f.parse(filename);
    };
  };

  Def def;
  Include include;
  enum { SYM_MAXLEN = 32 };
  enum Token1 { END, LINE, CTRL, SPACE, COMMENT, PUNC, OPAREN, CPAREN,
		DIGIT, UPPER, IDENT, LOWER, OBRACK, CBRACK, OCURLY, CCURLY };
  int lineNum;
  map<String, Action*> keywords;
  map<String, Action*> typeMap;

  static Token1 transition[256];

  static inline void endLine(const char*& p) {
    while (transition[*p] > LINE) {
      p++;
    }
  }

  static inline  void errorEndline(int line, const char text[], const char msg[], const char*& p) {
    cerr << line << ": " << msg << " " << text << "\n";
    endLine(p);
  }

  static inline String getToken(const char*& p) {
    const char* start = p;
    do {
      p++;
    } while (isalnum(*p));
    if (p - start > SYM_MAXLEN) {
      error(lineNum, start, "Maximum symbol length exceeded", p);
    }
    return String(start, p-start);
  }
public:
  ConfigFile(String filename) : def(*this, "define"), include(*this, "include") {
    
    lineNum = 0;
    //    String k("define");
    keywords["define"] = &def;
    keywords["include"] = &include;
    parse(filename);
  }


  void parse(const String& filename) {
    readFileCompletely(filename, buf, len);
    parseConfigFile(buf, len);
  }

  void parseConfigFile(const char buf[], size_t len) {
    const char* p = buf;
    while (true) {
      switch (transition[*p]) {
      case END: return;
      case CTRL: break;
      case SPACE: break;
      case LINE: lineNum++; break;
      case COMMENT:
	endLine(p);
	if (transition[*p] == END) {
	  return;
	} else {
	  p++;
	  lineNum++;
	}
	break;
      case PUNC:
	error(lineNum, p, "Expected identifier");
	break;
      case UPPER:
      case LOWER:
      case DIGIT:
      case IDENT:
	String sym = getToken(p);
	map<String,Action*>::iterator ki= keywords.find(sym);
	if (ki != keywords.end()) {
	  cout << "Found keyword: " << sym << "\n";
	  Action* a = ki->second;
	  (*a)(lineNum, p);
	} else {
	  map<String,Action*>::iterator ti= typeMap.find(sym);
	  if (ti == typeMap.end()) {
	    errorEndline(lineNum, p, "symbol name not found in metadata", p);
	    break;
	  }
	  cout << "found type in metadata\n";
	  break;
	}
      }
      p++;
    }
  }
};

