#ifndef RECT_H
#define RECT_H

#include"Shape.h"
class Rect:public Shape
{
public:
	Rect(double width, double height);
	virtual ~Rect();
	virtual double calArea();
private:
	double m_dWidth;
	double m_dHeight;
};

#endif
