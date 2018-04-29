#ifndef ANT_H
#define ANT_H

#include"Insect.h"

class Ant:public Insect
{
public:
	Ant();
	virtual ~Ant();
	virtual void play();
	void work();
};

#endif
