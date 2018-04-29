#include"Hyper.h"
#include<iostream>
using namespace std;

Hyper::Hyper(std::string engine, std::string name):Car(name)
{
	m_strEngine = engine;   //this class only has m_strEngine
	cout<<"Hyper()"<<endl;
}

Hyper::~Hyper()
{
	cout<<"~Hyper()"<<endl;
}

void Hyper::accelerate()
{
	cout<<m_strEngine<<endl;
}