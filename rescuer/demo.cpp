#include"Rescuer.h"
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int ram = 32;
	int dram = 3;

	cout<<"****************"<<endl;
	Rescuer* r = new Rescuer(ram,dram); //Rescuer has two para
	
	float p = r->performance();
	r->Datamining();
	r->Gaming();

	cout<<"****************"<<endl;
	delete r;
	r=NULL;

	return 0;
}