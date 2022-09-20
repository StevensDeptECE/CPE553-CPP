CXX	:= g++ -std=c++20
DEBUG	:= -g
OPT	:= -O2

all: lib1.a lib2.so main benchmarks.o

clean:
	rm *.o lib1.a lib2.so

lib1.a:	lib1.cc lib1.hh
	$(CXX) $(DEBUG) $(OPT) -c lib1.cc
	ar rvs lib1.a lib1.o

lib2.so:lib2.cc lib2.hh
	$(CXX) $(DEBUG) $(OPT) -fPIC -c lib2.cc
	$(CXX) -shared lib2.o -o lib2.so

main: main.o benchmarks.o lib1.a lib2.so
	$(CXX) $(DEBUG) $(OPT) -c benchmarks.cc
	$(CXX) $(DEBUG) main.o benchmarks.o -llib1 -L. -llib2 -o main
	ldd main

main.o: main.cc ../../lib/benchmark.hh
	$(CXX) -I../../lib $(DEBUG) $(OPT) -c main.cc

