OBJ	:= FractionMain.o Fraction.o
fraction: $(OBJ)
	g++ -g $(OBJ) -o fraction

Fraction.o: Fraction.cc
	g++ -g -c $<

FractionMain.o: FractionMain.cc
	g++ -g -c $<
