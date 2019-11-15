separate: main.cc f.cc
	g++ -g main.cc f.cc -o separate


separate2: main.o f.o
	g++ -g main.o f.o -o separate2

main.o: main.cc
	g++ -c -g main.cc


f.o: f.cc
	g++ -c -g f.cc

