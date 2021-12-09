DEBUG	:=	-g
CXX	:=	g++ $(DEBUG)


complex: main.o
	$(CXX) $^ -o complex


main.o: main.cc Complex.hh
	$(CXX) -c $<

#Complex.o: Complex.cc Complex.hh
#	$(CXX) -c $<

clean:
	rm *.o complex
