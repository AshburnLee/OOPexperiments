#include"Rescuer.h"
#include<iostream>
using namespace std;

//pass ram & dram to Computer & Gamestation
Rescuer::Rescuer(int ram, int dram): Computer(ram),Gamestation(dram)
{

}

Rescuer::~Rescuer(){}

float Rescuer::performance()
{
	float para = 0.4 * m_iRAM + 0.6 * m_iDRAM;
	cout<<"Peformance of Rescuer: "<<para<<endl;
}