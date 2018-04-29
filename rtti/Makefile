demo:demo.o Bird.o Plane.o
	g++ demo.o Bird.o Plane.o -o demo

demo.o:demo.cpp
	g++ -std=c++11 -c demo.cpp

Bird.o:Bird.cpp Bird.h
	g++ -c Bird.cpp

Plane.o:Plane.cpp Plane.h Flyable.h
	g++ -c Plane.cpp

clean:
	rm *.o demo
