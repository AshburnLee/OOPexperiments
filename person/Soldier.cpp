#include"Soldier.h"
#include<iostream>

Soldier::Soldier()
{
	std::cout<<"Soldier()"<<"\n";
}

Soldier::~Soldier()
{
	std::cout<<"~Soldier()"<<"\n";
}

int Soldier::work(int x)
{
	std::cout<<"im working:"<<"\n";
	m_iAge = x*x;         // child
	m_strName = "Ross";  // father
	std::cout<<m_strName<<" "<<m_iAge<<'\n';
}


