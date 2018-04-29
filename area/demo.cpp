#include<iostream>
#include"Circle.h"
#include"Rect.h"
using namespace std;

int main(int argc, char** argv)
{
	Shape* shape1 = new Circle(6);
	Shape* shape2 = new Rect(3,5);
	shape1->calArea();
	shape2->calArea();

	delete shape1;
	shape1=NULL;
	delete shape2;
	shape2=NULL;
	return 0;
}

