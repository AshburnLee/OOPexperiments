#ifndef WORKER_H
#define WORKER_H

#include"Person.h"
class Worker: public Person
{
public:
	Worker(std::string name,int age);
	virtual ~Worker(){}
	//virtual void work();
private:
	int m_iAge;
};

#endif