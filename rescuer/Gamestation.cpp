#include"Gamestation.h"
#include<iostream>

using namespace std;

Gamestation::Gamestation(int dram)  //
{
	m_iDRAM = dram;
	//cout<<"Gamestation()"<<endl;
}
Gamestation::~Gamestation()
{
	//cout<<"~Gamestation()"<<endl;
}

void Gamestation::Gaming()
{
	m_strGPU = "Nvidia_Geforce_1050";
	cout<<"GPU: \t"<<m_strGPU<<"\nDRAM; \t"<<m_iDRAM<<endl;
	
	if(m_iDRAM<2){
		cout<<"You can not gaming!"<<endl;
	}
	else{
		cout<<"You can gaming"<<endl;
	}

	
}