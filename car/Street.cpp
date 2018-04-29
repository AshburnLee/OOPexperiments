#include"Street.h"
#include<iostream>
#include<string>
using namespace std;

Street::Street(int turbo, std::string name):Car(name)
{
	m_iTurbo = turbo;  // this class only has m_iTurbo
	cout<<"Street()"<<endl;
}

Street::~Street()
{
	cout<<"~Street()"<<endl;
}

void Street::drift()
{
	cout<<"**************"<<endl;
	cout<<m_strName<<endl;
	cout<<m_iTurbo<<endl;
	cout<<"Difting~~~"<<endl;
}