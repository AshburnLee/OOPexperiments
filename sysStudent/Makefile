demo: demoMain.o StudentRecord.o
	g++ demoMain.o StudentRecord.o -o demo

demoMain.o: demoMain.cpp
	g++ -c demoMain.cpp

StudentRecord.o: StudentRecord.cpp StudentRecord.h
	g++ -c StudentRecord.cpp

clean:
	rm *.o
