#include"Computer.h"
#include"Gamestation.h"
#include<iostream>

class Rescuer: public Computer, public Gamestation
{
public:
	Rescuer(int ram, int dram);
	virtual ~Rescuer();
	float performance();
};