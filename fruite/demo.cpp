#include<iostream>
#include"Apple.h"

using namespace std;

void test1(Fruite);
void test2(Fruite&);
void test3(Fruite*);

int main(int argc, char** argv)
{
	std::string NAME = "fruite_is_sweet";
	int AGE = 66;

	Apple a0(NAME,AGE);
	Fruite f0;
	f0 = a0; //apple write to f0, 
	f0.grow(); 

	cout<<"*****************"<<endl;
	Apple a1(NAME,AGE);
	Fruite* f1=&a1;
	f1->grow();

	cout<<"*****************"<<endl;
	Fruite *p = new Apple(NAME,AGE);
	p -> grow();
	delete p;
	p=NULL;
	cout<<"*****************"<<endl;

	Fruite f2;
	Apple a2(NAME,AGE);
	test3(&f2);
	test3(&a2);


	return 0;
}

void test1(Fruite p)
{
	p.grow();
}
void test2(Fruite &p)
{
	p.grow();
}
void test3(Fruite* p)
{
	p->grow();
}