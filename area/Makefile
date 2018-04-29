demo:demo.o Rect.o Circle.o Shape.o
	g++ demo.o Rect.o Circle.o Shape.o -o demo

demo.o:demo.cpp
	g++ -c demo.cpp

Rect.o:Rect.cpp Rect.h
	g++ -c Rect.cpp

Circle.o:Circle.cpp Circle.h
	g++ -c Circle.cpp

Shape.o:Shape.cpp Shape.h
	g++ -c Shape.cpp
clean:
	rm *.o demo
