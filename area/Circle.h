#ifndef CIRCLE_H
#define CIRCLE_H

#include"Shape.h"
class Circle:public Shape
{
public:
	 Circle(double r);
	virtual ~Circle();
	double calArea();
private:
	double m_dR;
};

#endif
