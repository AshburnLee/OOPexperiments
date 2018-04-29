demo: demo.o Rescuer.o Gamestation.o Computer.o
	g++ demo.o Rescuer.o Gamestation.o Computer.o -o demo

demo.o: demo.cpp
	g++ -c demo.cpp

Rescuer.o: Rescuer.cpp Rescuer.h
	g++ -c Rescuer.cpp

Gamestation.o: Gamestation.cpp Gamestation.h
	g++ -c Gamestation.cpp

Computer.o: Computer.cpp Computer.h
	g++ -c Computer.cpp

clean:
	rm *.o demo