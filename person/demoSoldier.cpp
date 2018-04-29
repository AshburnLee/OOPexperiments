#include<iostream>
#include<stdlib.h>
//#include"Soldier.h"
#include"Infantry.h"

int main(int argc, char** argv)
{
	Infantry infantry;
	int y = infantry.work(1);   // in public
	
	infantry.attack(); // in public
	//soldier.eat();
	return 0;
}
