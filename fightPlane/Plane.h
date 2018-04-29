#ifndef PLANE_H
#define PLANE_H

#include<string>
using namespace std;

class Plane
{
public:
	Plane(string code);
	virtual ~Plane();
	void printCode();
private:
	string m_strCode;
};

#endif