#include<iostream>
#include"Stack.h"
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	try{
		Stack<int> intStack;

		cout<<intStack.empty()<<endl;
		intStack.push(7);
		cout<<intStack.empty()<<endl;
		for (int i=0;i<10;i++){
			intStack.push(i);
		}
		intStack.printElem();
		
		
	}catch(std::exception e){
		cerr<<"exception: "<<e.what()<<endl;
	}	return -1;
	
	return 0;
}