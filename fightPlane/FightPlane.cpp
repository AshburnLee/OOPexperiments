#include"FightPlane.h"
#include<iostream>
using namespace std;

FightPlane::FightPlane(string code):Plane(code)
{}
void FightPlane::takeoff()
{
	cout<<"fightPlane::takeoff"<<endl;
}

void FightPlane::land()
{
	cout<<"FightPlane::land"<<endl;
}