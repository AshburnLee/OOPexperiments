#include<iostream>
#include"Line.h"

int main(int argc,char** argv)
{
	Line* p = new Line(1,3,5,7);

	p->printInfo();
	delete p;
	p=NULL;

	return 0;
}