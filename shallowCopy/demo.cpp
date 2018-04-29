#include"Array.h"
#include<iostream>
using namespace std;

int main(int argc,char** argv)
{
	Array arr1(5);
	

	Array arr2(arr1);  // copy arr1 to arr2.
	arr2.printAddr();
	arr1.printAddr();
	return 0;
}