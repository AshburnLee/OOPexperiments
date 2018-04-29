#include <iostream>
#include <string>
#include"FightPlane.h"
using namespace std;

void flyFight(Flyable*);
void flyFightCode(Plane*);
int main(int argc,char** argv)
{
	// Plane p1("001");
	// Plane p2("002");
	// p1.printCode();
	// p2.printCode();
	// flyFight(&p1, &p2);

	FightPlane* f1 = new FightPlane("101");
	flyFight(f1);
	flyFightCode(f1);
	return 0;
}

void flyFight(Flyable* f1) //pass the child of Flyable
{
	//call pure vf
	f1->takeoff();
	f1->land();
}
void flyFightCode(Plane* p)
{
	p->printCode();
}
