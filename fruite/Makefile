demo: demo.o Fruite.o Apple.o
	g++ demo.o Fruite.o Apple.o -o demo

demo.o: demo.cpp
	g++ -c demo.cpp

Fruite.o: Fruite.cpp Fruite.h
	g++ -c Fruite.cpp 

Apple.o : Apple.cpp Apple.h
	g++ -c Apple.cpp

clean:
	rm *.o demo
