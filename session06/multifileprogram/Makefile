#
# ninja is faster
#

# first example rule: inefficient because any change forces entire program to recompile
#
#myprog: a.cc b.cc c.cc
#	g++ a.cc b.cc c.cc -omyprog

#all: myprog myprog2 myprog3

myprog: a.o b.o c.o
	g++ a.o b.o c.o -o myprog

a.o: a.cc
	g++ -c a.cc

b.o: b.cc
	g++ -c b.cc

c.o: c.cc
	g++ -c c.cc


clean:
	rm *.o myprog
