#include"Array.h"
#include<iostream>
using namespace std;

Array::Array(int count):m_iCount(count)
{	
	m_pArr = new int[m_iCount]; //memalloc
	for(int i=0;i<m_iCount;i++){
		m_pArr[i] = i;
	}
	cout<<"Array()"<<endl;
}

Array::Array(const Array& arr)
{	
	m_iCount = arr.m_iCount;
	// (1)mem alloc new addr for new instance:
	m_pArr = new int[m_iCount];
	// (2)copy one by one:
	for (int i=0;i<m_iCount;i++){
		m_pArr[i] = arr.m_pArr[i]+10;
	}
	
	cout<<"Array() &"<<endl;
}

Array::~Array()
{
	delete[] m_pArr;
	m_pArr = NULL;
 	cout<<"!Array()"<<endl;
}
void Array::printAddr()
{
	cout<<"the addr of m_pArr: "<<m_pArr<<endl;
}
void Array::printArr()
{
	for(int i=0;i<m_iCount;i++){
		cout<<m_pArr[i]<<endl;  //m_pArr[i] 
	}
	cout<<'\n';
}
