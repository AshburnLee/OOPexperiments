
demo:demoLine.o Line.o Coordinate.o
	g++ demoLine.o Line.o Coordinate.o -o demo

demoLine.o:demoLine.cpp
	g++ -c demoLine.cpp

Line.o:Line.cpp Line.h
	g++ -c Line.cpp

Coordinate.o:Coordinate.cpp Coordinate.h
	g++ -c Coordinate.cpp

clean:
	rm *.o demo