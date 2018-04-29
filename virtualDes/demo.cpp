#include<iostream>
#include"Rect.h"
#include"Circle.h"
using namespace std;	
int main(int argc,char** argv)
{
	//polymorphism:
	//Shape* shape1 = new Rect(1,2);
	//Shape* shape2 = new Circle(8);
	//shape1->calArea();
	//shape2->calArea();
	// no polymorphism:	
	Rect rect(1,2);
	Circle circle(8);
	rect.calArea();
	circle.calArea();
	
	// no polymorphism:
	Rect* r = new Rect(1,2);
	Circle* c = new Circle(6);
	r->calArea();
	c->calArea();
	//Shape shape;

	// int* p = (int*)&shape1;
	// cout<<p<<endl;

	// Circle* circle = new Circle(4);
	//Circle circle(4);
	//int* q = (int*)&circle;
	//cout<<q<<endl;	
		
	//cout<<(unsigned int)(*q)<<endl;	

	//cout<<sizeof(shape1)<<endl;
	//cout<<sizeof(shape)<<endl;
	


	delete shape1;
	shape1=NULL;
	delete shape2;
	shape2=NULL;

	return 0;
}
