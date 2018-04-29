#include<iostream>
#include"Shape.h"
using namespace std;

Shape::Shape()
{
	cout<<"Shape()"<<endl;
}

Shape::~Shape()
{
	cout<<"~Shape()"<<endl;
}

double Shape::calArea()
{
	cout<<"Shape-->calArea"<<endl;
	return 0;
}

