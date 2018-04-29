#include"Array.h"
#include<iostream>
using namespace std;

Array::Array(int count):m_iCount(count)
{	
	m_pArr = new int[m_iCount]; //memalloc
	cout<<"Array()"<<endl;
}

Array::Array(const Array& arr)
{	
	m_pArr = arr.m_pArr;
	m_iCount = arr.m_iCount;
	cout<<"Array() &"<<endl;
}

Array::~Array()
{
	delete[] m_pArr;
	m_pArr = NULL;
 	cout<<"!Array()"<<endl;
}
// void Array::setCount(int count)
// {
// 	m_iCount = count;
// }

// int Array::getCount()
// {
// 	return m_iCount;
// }
void Array::printAddr()
{
	cout<<"the addr of m_pArr: "<<m_pArr<<endl;
}

