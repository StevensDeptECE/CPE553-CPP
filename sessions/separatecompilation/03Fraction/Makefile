CXX	:=	g++
DEBUG	:=	#-g
OPT	:=	-O2

COMP	:=	$(CXX) $(DEBUG) $(OPT) -c

FRACOBJ	:= Fraction.o main.o 
fraction: $(FRACOBJ)
	$(CXX) $(DEBUG) $(FRACOBJ) -o fraction  # g++ -O2 Fraction.o main.o -o fraction

Fraction.o: Fraction.cc Fraction.hh
	$(COMP) $<

main.o: main.cc Fraction.hh
	$(COMP) $<
