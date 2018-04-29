#include<iostream>
#include"Ant.h"
using namespace std;
Ant::Ant()
{ 
	m_strName="son";
}

Ant::~Ant()
{
	cout<<"~Ant()"<<endl;
}

void Ant::play()
{
	cout<<"Ant::play()"<<endl;
}

void Ant::work()
{
	Insect::m_strName = "parent "; 
	cout<<Insect::m_strName<<" is working"<<endl;
}
