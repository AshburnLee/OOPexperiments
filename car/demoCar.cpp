#include"Mustang.h"
#include<iostream>
using namespace std;

int main(int argc,char** argv)
{
	string NAME = "mustang";
	string ENGINE = "w10";
	int TURBO = 4;

	Mustang*m = new Mustang(ENGINE,TURBO,NAME);
	m->drift();
	m->accelerate();

	delete m;
	m=NULL;

	return 0;
}