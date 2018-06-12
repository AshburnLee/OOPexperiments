demo: demoMain.o Account.o
	g++ demoMain.o Account.o -o demo

demoMain.o: demoMain.cpp
	g++ -c demoMain.cpp

Account.o: Account.cpp Account.h
	g++ -c Account.cpp

clean:
	rm *.o demo
