#ifndef MAZER_H
#define MAZER_H
#include<windows.h>
#include"MazerMap.h"

class Mazer
{
public:
	Mazer();
	~Mazer();
	bool walkUp();
	bool walkDown();
	bool walkRight();
	bool walkLeft();

	//current popsition
	void setPosition(int x,int y);
	void setHero(char hero);
	void setDirection(char direction);
	void moveForward(char direction);
	void setMap(MazeMap* map);
	void start();
	int getSteps();
private:
	char m_cHero;
	char m_cHeroLookAt;
	COORD m_heroCurrentPosition;
	MazerMap *m_pMap;
	int m_iSteps;
};
