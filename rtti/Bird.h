#ifndef BIRD_H
#define BIRD_H

#include <iostream>
#include <string>
#include "Flyable.h"
using namespace std;

class Bird:public Flyable
{
public:
	virtual void takeoff();
	virtual void land();
	void forging();
};
#endif