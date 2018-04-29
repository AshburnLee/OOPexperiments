#ifndef FIGHTPLANE_H
#define FIGHTPLANE_H

#include <iostream>
#include <string>
#include "Plane.h"
#include "Flyable.h"
using namespace std;

class FightPlane:public Plane, public Flyable
{
public:
	FightPlane(string code);
	virtual void takeoff();
	virtual void land();
};
#endif