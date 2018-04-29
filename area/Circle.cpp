#include<iostream>
#include"Circle.h"
using namespace std;

Circle::Circle(double r):m_dR(r)
{
	cout<<"Circle()"<<endl;	
}

Circle::~Circle()
{
	cout<<"~Circle()"<<endl;
}

double Circle::calArea()
{
	cout<<"Circle-->calArea"<<endl;
	return 3.1415 * m_dR * m_dR;
}

