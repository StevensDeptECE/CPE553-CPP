CXX	:=	g++
DEBUG	:=	-g

FRACOBJ	:= Fraction.o main.o 
fraction: $(FRACOBJ)
	$(CXX) $(DEBUG) $(FRACOBJ) -o fraction

Fraction.o: Fraction.cc Fraction.hh
	$(CXX) $(DEBUG) -c $<

main.o: main.cc Fraction.hh
	$(CXX) $(DEBUG) -c $<
