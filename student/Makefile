demo: demo.o Student.o
	g++ demo.o Student.o -o demo

demo.o: demo.cpp
	g++ -c demo.cpp

Student.o: Student.cpp Student.h
	g++ -c Student.cpp

clean:
	rm *.o demo