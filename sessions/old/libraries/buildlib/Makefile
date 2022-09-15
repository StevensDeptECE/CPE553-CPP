all: libstats.a libstats.so

libstats.a: statslib.cc
	g++ -c -g statslib.cc
	ar rs libstats.a statslib.o

libstats.so: statslib.cc
	g++ statslib.cc -shared -o libstats.so


libstats2.so:
	
