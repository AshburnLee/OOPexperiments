#include<iostream>
#include"Person.h"

Person::Person()
{
	m_strName = "Logan";
	std::cout<<m_strName<<std::endl;
}

Person::~Person()
{
	std::cout<<"~Person()"<<std::endl;
}

void Person::play()
{
	std::cout<<"im palying"<<std::endl;
	std::cout<<m_strName<<"\n";
}

int Person::eat(int x)
{
	return x*x;
	std::cout<<"i am eating"<<" "<<x*x<<" "<<std::endl;
}
