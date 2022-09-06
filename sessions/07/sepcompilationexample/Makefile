CXX	:=	g++
DEBUG	:=	-g
OPT	:=	#-O2

fraction: main.o Fraction.o
	 $(CXX) $(DEBUG) main.o Fraction.o -o fraction

main.o: main.cc
	$(CXX) $(DEBUG) -c main.cc

Fraction.o: Fraction.cc
	$(CXX) $(DEBUG) -c Fraction.cc

clean:
	rm *.o fraction.exe
