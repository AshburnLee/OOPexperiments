#include"Student.h"
#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	Student s1;
	Student s2("Lisa", 34.65);
	Student s3("Joe");        //default score value 

	s2.setGender("Female");
	//s1.initScore(); //need to call func to activate it
	cout<<s1.getName()<<" "<<s1.getGender()<<" "<<s1.getScore()<<"\n";
	cout<<s2.getName()<<" "<<s2.getGender()<<" "<<s2.getScore()<<"\n";
	cout<<s3.getName()<<" "<<s3.getGender()<<" "<<s3.getScore()<<"\n";

	return 0;
}