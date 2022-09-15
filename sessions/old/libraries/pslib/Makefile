all: testGraph2dNoDB

testGraph2d: testGraph2d.cc Graph2D.cc Graph2D.hh util/StringBuffer.hh Makefile
	g++ -g -Iutil/  -I /usr/include/mysql -I /usr/local/include/mysql++/ testGraph2d.cc Graph2D.cc  -lmysqlpp -o testGraph2d

testGraph2dNoDB: testGraph2dNoDB.cc Graph2D.cc Graph2D.hh util/StringBuffer.hh Makefile
	g++ -g -Iutil/  testGraph2dNoDB.cc Graph2D.cc  -o testGraph2dNoDB

teststringbuf: teststringbuf.cc util/StringBuffer.hh util/GrowArray.hh
	g++ -g -O2 -Iutil/teststringbuf.cc -o teststringbuf

