demo:demo.o Dustman.o Worker.o Person.o
	g++ demo.o Dustman.o Worker.o Person.o -o demo
demo.o:demo.cpp
	g++ -c demo.cpp

Dustman.o:Dustman.cpp Dustman.h
	g++ -c Dustman.cpp

Worker.o:Worker.cpp Worker.h
	g++ -c Worker.cpp

Person.o:Person.cpp Person.h
	g++ -c Person.cpp

clean:
	rm *.o demo