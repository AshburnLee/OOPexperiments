#include<iostream>
#include"Coordinate.h"
using namespace std;

int main(int argc, char** argv)
{
	Coordinate* p1 = NULL;
	p1 = new Coordinate;
	Coordinate* p2 = new Coordinate();

	p1->m_iX = 10;
	p1-> m_iY = 20;
	(*p2).m_iX = 30;
	(*p2).m_iY = 40;
	cout<<p1->m_iX+(*p2).m_iX<<endl;
	
	delete p1; 
	p1=NULL;
	delete p2;
	p2=NULL;

	Coordinate p3;
	Coordinate* p4 = &p3;
	p4->m_iX = 10;
	p4->m_iY = 20;
	cout<<p3.m_iX<<" "<<p3.m_iY<<endl;
	

	return 0;
}