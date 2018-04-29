#include"Ant.h"
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	Ant ant;
	
	ant.play();
	ant.Insect::play();  
	//ant.work();
	
	return 0;
}
