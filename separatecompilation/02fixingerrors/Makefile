myprog: main.o f.o
	g++ main.o f.o -o myprog

main.o: main.cc f.hh
	g++ -c main.cc

f.o: f.cc f.hh
	g++ -c f.cc

clean:
	rm *.o myprog

