OBJ := main.o Circle.o Rect.o Shape.o

geometry: $(OBJ)
	g++ -g $(OBJ) -o geometry

Circle.o: Circle.cc Circle.hh Shape.hh
	g++ -g -c Circle.cc

Rect.o: Rect.cc Rect.hh Shape.hh
	g++ -g -c Rect.cc

Shape.o: Shape.cc Shape.hh
	g++ -g -c Shape.cc

main.o: main.cc Circle.hh Rect.hh Shape.hh
	g++ -g -c main.cc

clean:
	rm *.o geometry
