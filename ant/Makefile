demo: demoCover.o Ant.o Insect.o
	g++ demoCover.o Ant.o Insect.o -o demo

demoCover.o: demoCover.cpp
	g++ -c demoCover.cpp

Ant.o: Ant.cpp Ant.h
	g++ -c Ant.cpp

Insect.o: Insect.cpp Insect.h
	g++ -c Insect.cpp

clean:
	rm *.o demo
