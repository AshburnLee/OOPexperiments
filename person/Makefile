demo: demoSoldier.o Infantry.o Soldier.o Person.o
	g++ demoSoldier.o Infantry.o Soldier.o Person.o -o demo

demoSoldier.o: demoSoldier.cpp
	g++ -c demoSoldier.cpp

Infantry.o: Infantry.cpp Infantry.h
	g++ -c Infantry.cpp

Soldier.o: Soldier.cpp Soldier.h
	g++ -c Soldier.cpp

Person.o: Person.cpp Person.h
	g++ -c Person.cpp

clean:
	rm *.o demo
