#include"Apple.h"
#include<iostream>
using namespace std;

Apple::Apple(std::string name, int age)
{
	m_strName = name;
	m_iAge = age;
	cout<<"Apple()"<<endl;
}

Apple::~Apple()
{
	cout<<"~Apple()"<<endl;
}

void Apple::roll()
{
	cout<<m_strName<<endl;
	cout<<m_iAge<<endl;
	cout<<"im rolling"<<endl;
}