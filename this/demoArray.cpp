#include<iostream>
#include"Array.h"
using namespace std;

int main(int argc,char** argv)
{
	Array arr1(10);
	//did not change 10
	//arr1.printInfo().setLen(5);	
	//cout<<"len="<<arr1.getLen()<<endl;
	//cout<<""<<endl;
	// Array.Array.Array.func() 
	arr1.printInfo2().setLen2(5).printInfo(); 
	arr1.printInfo3()->setLen3(3)->printInfo();	
	arr1.printAddr();
	cout<<&arr1<<endl;
	return 0;
}

