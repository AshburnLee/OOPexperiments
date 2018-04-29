#include"Car.h"
#include<string>

class Street:virtual public Car
{
public:
	Street(int turbo=4, std::string name="Street_car");
	virtual ~Street();
	void drift();
protected:
	int m_iTurbo;
};