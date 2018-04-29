demo:demoArray.o Array.o
	g++ demoArray.o Array.o -o demo

demoArray.o:demoArray.cpp 
	g++ -c demoArray.cpp

Array.o:Array.cpp Array.h
	g++ -c Array.cpp
clean:
	rm *.o demo
