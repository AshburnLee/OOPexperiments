#include<iostream>
#include<stdlib.h>
#include<string>
#include"Mazer.h"
#include"MazeMap.h"
#include<windows.h>

using namespace std;

int main(int argc, char** argv)
{
	//定义并初始化存储地图数据的二维数组
	int map[11][11] = {
		{WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL},
		{WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, ROAD},
		{WALL, ROAD, WALL, WALL, WALL, ROAD, WALL, WALL, WALL, ROAD, WALL},
		{WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, WALL},
		{WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, ROAD, WALL, WALL, WALL},
		{WALL, ROAD, WALL, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, WALL},
		{WALL, ROAD, WALL, WALL, WALL, WALL, WALL, WALL, WALL, ROAD, WALL},
		{WALL, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, WALL, ROAD, WALL},
		{WALL, WALL, WALL, ROAD, WALL, WALL, WALL, ROAD, WALL, ROAD, WALL},
		{ROAD, ROAD, ROAD, ROAD, WALL, ROAD, ROAD, ROAD, ROAD, ROAD, WALL},
		{WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}
	};
	MazeMap& mm = new MazeMap('H');
	COORD exitPosition;
	exitPosition.X = 0;
	exitPosition.Y = 9;

	mm->setMap(&map[0][0],11,11);

	mm->setExitPosition(exitPosition);

	mm->printMap();

	string emptySpace(5,'\n');
	cout<<enptySpace;

	Mazer* mzr = new Mazer();

	mzr->setHero('o');

	mzr->setPosition(10,1);
	mzr->setDirection('D');
	mzr->setMap(mm);
	mzr->start();

	cout<<"Totl steps: "<<mzr->getSteps()<<endl;

	delete mzr;
	mzr=NULL;
	delete mm;
	mm=NULL;

	return 0;


}