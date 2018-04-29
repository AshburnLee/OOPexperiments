#ifndef PERSON_H
#define PERSON_H

#include<string>
using namespace std;

class Person
{
public:
	Person(string name);
	virtual ~Person(){}
	virtual void work()=0;  //too abstract
private:
	string m_strName;
};

#endif