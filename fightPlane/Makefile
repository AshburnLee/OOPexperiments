demo:demo.o FightPlane.o Plane.o
	g++ demo.o FightPlane.o Plane.o -o demo

demo.o:demo.cpp
	g++ -c demo.cpp

FightPlane.o:FightPlane.cpp FightPlane.h
	g++ -c FightPlane.cpp

Plane.o:Plane.cpp Plane.h Flyable.h
	g++ -c Plane.cpp

clean:
	rm *.o demo
