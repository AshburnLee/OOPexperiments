#include <iostream>
#include <string>
#include <typeinfo>
#include <typeindex>
#include"Plane.h"
#include"Bird.h"
using namespace std;

void doSomething(Flyable*);

int main(int argc,char** argv)
{
	char* a=NULL;
	cout<<typeid(a).name()<<endl;

	Flyable* p = new Plane();
	cout<<typeid(p).name()<<endl;
	cout<<typeid(*p).name()<<endl;

	Bird* f1 = new Bird();
	doSomething(f1);
	return 0;
}

void doSomething(Flyable* obj) //pass the child of Flyable
{
	cout<<typeid(*obj).name()<<endl;
	obj->takeoff();

	if(typeid(*obj)==typeid(Bird)){
		Bird *bird = dynamic_cast<Bird*>(obj);
		bird->forging();
	}
	if(typeid(obj)==typeid(Plane)){
		Plane *plane = dynamic_cast<Plane*>(obj);
		plane->carry();
	}

	obj->land();
}

