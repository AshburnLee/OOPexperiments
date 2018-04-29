#include<iostream>
#include"Coordinate.h"
using namespace std;

int main(int argc, char** argv)
{
	Coordinate coor[3]; 
	for (int i=0;i<3;i++){
		cout<<coor[i].m_iX<<endl;
		cout<<coor[i].m_iY<<endl;
	}

	Coordinate* ptr = new Coordinate[3];

	ptr->m_iX = 100;
	ptr[0].m_iY = 200;

	ptr++;
	ptr->m_iX = 11;
	ptr[0].m_iY = 13;

	ptr[1].m_iX = 15;
	ptr++;
	ptr->m_iY = 17;

	//only do this without ptr++.
	for (int i=0;i<3;i++){
		cout<<ptr[i].m_iX<<endl;
		cout<<ptr[i].m_iY<<endl;
	}

	//ptr is not moving, so it only print the first coor[0]
	for (int i=0;i<3;i++){
		cout<<ptr->m_iX<<endl;
		cout<<ptr->m_iY<<endl;
	}

	for (int i=0;i<3;i++){
		cout<<ptr->m_iX<<endl;
		cout<<ptr->m_iY<<endl;
		ptr=ptr+1;
	}
	ptr--;

	//infinitly call deconstructor??????
	delete ptr; 
	ptr=NULL;

	return 0;
}