#include"Mustang.h"
#include<iostream>
using namespace std;

Mustang::Mustang(string engine, int turbo,string name):Hyper(engine,name),Street(turbo,name)
{
	cout<<m_strEngine<<" "<<m_iTurbo<<" "<<m_strName<<endl;
	cout<<"Mustang()"<<endl;
}

Mustang::~Mustang()
{
	cout<<"~Mustang()"<<endl;
}