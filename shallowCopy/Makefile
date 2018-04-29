demo:demo.o Array.o
	g++ demo.o Array.o -o demo

demo.o:demo.cpp
	g++ -c demo.cpp

Array.o:Array.cpp Array.h
	g++ -c Array.cpp

clean:
	rm *.o demo