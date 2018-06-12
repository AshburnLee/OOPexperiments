demo: demoMain.o Bank.o
	g++ demoMain.o Bank.o -o demo

demoMain.o: demoMain.cpp
	g++ -c -std=c++11 demoMain.cpp

Bank.o: Bank.cpp Bank.h
	g++ -c -std=c++11 Bank.cpp

clean:
	rm *.o demo
