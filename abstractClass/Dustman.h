#ifndef DUSTMAN_H
#define DUSTMAN_H
#include"Worker.h"
using namespace std;

class Dustman:public Worker
{
public:
	Dustman(string name, int age);
	virtual ~Dustman();
	virtual void work(); // 
};

#endif