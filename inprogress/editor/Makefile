CXX	:= g++ -g #-O2
OBJ	:= editor.o dkedit.o text_win.o
editor: $(OBJ)
	$(CXX) 	$(OBJ) -o editor

editor.o: editor.cc editor.hh text_win.hh
	$(CXX) -c $<

dkedit.o: dkedit.cc
	$(CXX) -c $<

text_win.o: text_win.cc text_win.hh
	$(CXX) -c $<

clean:
	rm *.o editor
