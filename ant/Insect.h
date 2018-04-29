#ifndef INSECT_H
#define INSECT_H

#include <string>

class Insect
{
public:
	Insect();
	virtual ~Insect();
	virtual void play();
protected:
	std::string m_strName;
};

#endif
