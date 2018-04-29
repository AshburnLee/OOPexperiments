#include"Dustman.h"
#include<iostream>
#include"Worker.h"

int main(int argc, char** argv)
{
	//Person person("lal"); //abstract error
	//Worker worker("La",67);
	//worker.work();
	// Person* person = new Worker("Las", 34);
	// person->work();
	Dustman d("ladf",34);
	d.work();
	// delete person;
	// person=NULL;
	return 0;
}