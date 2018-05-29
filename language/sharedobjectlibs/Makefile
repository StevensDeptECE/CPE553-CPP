all: sample.so testso

sample.so: sampleso.c
	gcc -fPIC -c sampleso.c
	gcc -shared -fPIC -g sampleso.o -o sample.so

testso: testdll.cc
	g++ testdll.cc -o testso -ldl

clean:
	rm sample.so test
