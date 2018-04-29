#include"Fruite.h"

class Apple:public Fruite
{
public:
	Apple(std::string name, int age);
	virtual ~Apple();
	void roll();
protected:
	int m_iAge;
};
