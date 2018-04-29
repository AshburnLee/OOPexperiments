#include<iostream>
#include"Coordinate.h"
using namespace std;

Coordinate::Coordinate():m_iX(10),m_iY(20)
{
	cout<<"Coordinate()"<<endl;
}

Coordinate::~Coordinate()
{
	cout<<"~Coordinate()"<<endl;
}