// to cimpile this:
//   $ g++ Person.cpp Worker.cpp demoWorker.cpp

// OR: g++ -c Person.cpp -o Person.o
//     g++ -c Worker.cpp -o Worker.o
//     g++ Person.o Worker.o demoWorker.cpp -o demoWorker

// you need to compile all the .cpp files 
#include<iostream>
#include"Worker.h" 
//#include"Person.h"


int main(int argc, char** argv)
{
	// // allocate from heap as a pointer:
	// Worker* ptrJim = new Worker(); 

	// // sign values to attributes:
	// ptrJim->m_strName = "Jim";
	// ptrJim->m_iAge = 23;
	// ptrJim->m_Salary = 100000;

	// //call class methods:
	// ptrJim-> eat();
	// ptrJim-> work();
	// std::cout<<"salary:"<<ptrJim->m_Salary<<std::endl;

	// delete ptrJim;  //delete
	// ptrJim = NULL; // safe status


	// allocate in stack .
	Worker worker;
	
	worker.work();  //visit protected attributes,
	// Person person;

	// person.m_strName = "GUY";   // error m_strName is protected
	// person.m_iAge = 453;        // error m_iAge is private
	// person.eat();              // yeah, can visit 
	return 0;
}
