#include<iostream>
#include"Circle.h"
using namespace std;

Circle::Circle(double r):m_dR(r)
{
	cout<<"Circle()"<<endl;
	m_pCenter = new Coordinate(3,6);
}

Circle::~Circle()
{
	cout<<"~Circle()"<<endl;
	delete m_pCenter;
	m_pCenter=NULL;
}

double Circle::calArea()
{
	cout<<"Circle-->calArea"<<endl;
	return 3.1415 * m_dR * m_dR;
}

