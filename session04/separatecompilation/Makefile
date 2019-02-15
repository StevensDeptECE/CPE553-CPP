frac: Fraction.o main.o
	g++  Fraction.o main.o -o frac

Fraction.o: Fraction.hh Fraction.cc
	g++ -c Fraction.cc

main.o: main.cc Fraction.hh
	g++ -c main.cc
