#include"Insect.h"
#include<iostream>
using namespace std;

Insect::Insect():m_strName("parent")
{
}

Insect::~Insect()
{
	//cout<<"~Insect()"<<'\n';
}

void Insect::play()
{
	cout<<"Insect::play()"<<"\n";
}
