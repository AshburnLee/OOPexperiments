#include"Plane.h"
#include<iostream>
using namespace std;
Plane::Plane(string code):m_strCode(code){}

Plane::~Plane(){}

void Plane::printCode(){
	cout<<"code: "<<m_strCode<<endl;
}