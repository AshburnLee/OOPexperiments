#include<iostream>
#include<stdio.h> //sprintf()
#include<cstdlib>  //rand()
#include<ctime> //time()
using namespace std;

int main(void)
{

	srand(time(NULL));
	float x = rand()%5;
	cout<<x<<endl;

	char buffer[40];
	int n, a =3, b=8;
	n=sprintf(buffer, "%d plus %d is %d",a,b,a+b);
	printf("[%s] is a string of %d long chars\n",buffer, n);
	
	return 0;
}