#ifndef PLANE_H
#define PLANE_H
#include"Flyable.h"
#include<string>
using namespace std;

class Plane: public Flyable
{
public:
	virtual void takeoff();
	virtual void land();
	void carry();
};
#endif