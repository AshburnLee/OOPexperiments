#include<iostream>
#include"Line.h"
using namespace std;

int main(int argc,char** argv)
{
	Line* p = new Line(1,3,5,7);

	p->printInfo();
	delete p;
	p=NULL;

	cout<<sizeof(p)<<endl;
	cout<<sizeof(Line)<<endl;
	cout<<sizeof(Coordinate)<<endl;
	return 0;
}