demo: demoMaze.o Mazer.o MazeMap.o
	g++ demoMaze.o Mazer.o MazeMap.o -o demo

demoMaze.o: demoMaze.cpp
	g++ -c demoMaze.cpp

Mazer.o: Mazer.cpp Mazer.h
	g++ -c Mazer.cpp

MazeMap.o: MazeMap.cpp MazeMap.h
	g++ -c MazeMap.cpp

clean:
	rm *.o demo