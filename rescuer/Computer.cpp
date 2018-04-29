#include"Computer.h"
#include<iostream>

using namespace std;

Computer::Computer(int ram)
{	
	m_iRAM = ram;
	//cout<<"Computer()"<<endl;
}
Computer::~Computer()
{
	//cout<<"~Computer()"<<endl;
}

void Computer::Datamining()
{	
	m_strCPU = "i5_7Gen ";
	cout<<"CPU: \t"<<m_strCPU<<"\nRAM: \t"<<m_iRAM<<endl;

	if (m_iRAM < 8){
		cout<<"You are not capabale of Mining!"<<endl;
	}
	else{
		cout<<"You can do the mining job"<<endl;
	}
	

}