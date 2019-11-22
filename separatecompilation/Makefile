all: separate separate2 fraction

separate: main.cc f.cc
	g++ -g main.cc f.cc -o separate

separate2: main.o f.o
	g++ -g main.o f.o -o separate2

main.o: main.cc
	g++ -c -g main.cc

f.o: f.cc
	g++ -c -g f.cc


fraction: main2.o Fraction.o
	g++ -g main2.o Fraction.o -o fraction

main2.o: main2.cc
	g++ -g -c main2.cc

Fraction.o: Fraction.cc
	g++ -g -c Fraction.cc


