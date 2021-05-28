comp: Complex.o main.o
	g++ -g $^ -o $@

Complex.o: Complex.cc Complex.hh
	g++ -c $<

main.o: main.cc Complex.hh
	g++ -c $<

