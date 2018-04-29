#include"Car.h"
#include<string>

class Hyper:virtual public Car
{
public:
	Hyper(std::string engine="V8", std::string name="Sport_car");
	virtual ~Hyper();
	void accelerate();
protected:
	std::string m_strEngine;
};