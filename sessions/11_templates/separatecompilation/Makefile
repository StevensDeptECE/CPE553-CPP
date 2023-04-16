OBJ :=  main.o Circle.o Rect.o
shape: $(OBJ)
	g++ -g $(OBJ) -o shape

main.o: main.cc Shape.hh Circle.hh Rect.hh
	g++ -g -c $<

Circle.o: Circle.cc Circle.hh
	g++ -g -c $<

Rect.o: Rect.cc Rect.hh
	g++ -g -c $<