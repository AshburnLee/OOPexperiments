#include"Array.h"
#include<iostream>
using namespace std;

Array::Array(int len):m_iLen(len)
{
	cout<<"Array()"<<endl;
}
Array::~Array()
{
	cout<<"~Array()"<<endl;
}

void Array::setLen(int len)
{
	this->m_iLen = len;
}
Array& Array::setLen2(int len)
{
	this->m_iLen = len;
	return *this;
}
Array* Array::setLen3(int len)
{
	this->m_iLen = len;
	return this;
}

int Array::getLen()
{
	return m_iLen;
}

Array Array::printInfo()
{
	cout<<"len="<<m_iLen<<endl;
	return *this; // return a tmp Array obj!
}
Array& Array::printInfo2()
{
	cout<<"len="<<m_iLen<<endl;
	return *this;

}
Array* Array::printInfo3()
{
	cout<<"len="<<m_iLen<<endl;
	return this;
}
Array* Array::printAddr()
{
	cout<<this<<endl;
	return this;
}
