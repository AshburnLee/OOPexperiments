#ifndef CAR_H 
#define CAR_H 

#include<string>

class Car
{
public:
	Car(std::string name="machine");
	virtual ~Car();
	void ride();
protected:
	std::string m_strName;
};

#endif