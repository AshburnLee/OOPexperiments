demo: demoCar.o Mustang.o Street.o Hyper.o Car.o
	g++ demoCar.o Mustang.o Street.o Hyper.o Car.o -o demo

demoCar.o: demoCar.cpp
	g++ -c demoCar.cpp

Mustang.o: Mustang.cpp Mustang.h
	g++ -c Mustang.cpp

Street.o: Street.cpp Street.h
	g++ -c Street.cpp

Hyper.o: Hyper.cpp Hyper.h
	g++ -c Hyper.cpp

Car.o: Car.cpp Car.h
	g++ -c Car.cpp

clean:
	rm *.o demo