#include"Car.h"
#include<iostream>
using namespace std;

Car::Car(string name)
{
	m_strName = name;
	cout<<"Car()"<<endl;
}
Car::~Car()
{
	cout<<"~Car()"<<endl;
}
void Car::ride()
{
	cout<<m_strName<<endl;
}