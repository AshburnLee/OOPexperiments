#include<iostream>
#include"Person.h"

class Soldier:private Person
{
public:
	Soldier();
	~Soldier();
	int work(int);
protected:
	int m_iAge;
};