#include"Fruite.h"
#include<iostream>
using namespace std;

Fruite::Fruite(std::string name)
{
	m_strName = name;
	cout<<"Fruite()"<<endl;
}

Fruite::~Fruite()
{
	cout<<"~Fruite()"<<endl;
}

void Fruite::grow()
{
	cout<<m_strName<<endl;
	cout<<"Im growing"<<endl;
}