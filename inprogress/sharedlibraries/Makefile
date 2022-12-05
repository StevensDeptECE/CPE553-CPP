CXX	:= g++ -std=c++20
DEBUG	:= -g
OPT	:= -O2

# windows rule
all: libtest1.dll prog.exe

#comment out above and uncomment for linux
#all: libtest1.dll prog

clean:
	rm lib1.so

libtest1.so: lib1.cc lib1.hh
	$(CXX) $(DEBUG) $(OPT) -fPIC -c lib1.cc
	$(CXX) -shared lib1.o -o libtest1.so

libtest1.dll: lib1.cc lib1.hh
	$(CXX) $(DEBUG) $(OPT) -fPIC -c lib1.cc
	$(CXX) -shared lib1.o -o libtest1.dll

LIBS := -L . -ltest1

#for windows
prog.exe: main.cc g.cc libtest1.dll
	$(CXX) $(DEBUG) $(OPT) main.cc g.cc $(LIBS) -o prog

#for linux
#prog: main.cc libtest1.so
#	$(CXX) $(DEBUG) $(OPT) main.cc $(LIBS) -o prog
