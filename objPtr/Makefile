demo:demo.o Coordinate.o
	g++ demo.o Coordinate.o -o demo

demo.o:demo.cpp
	g++ -c demo.cpp

Coordinate.o:Coordinate.cpp Coordinate.h
	g++ -c Coordinate.cpp

clean:
	rm *.o demo