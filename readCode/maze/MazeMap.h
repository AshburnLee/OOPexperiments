#ifndef MAZEMAP_H
#define MAZEMAP_H

#include<windows.h>
#define WALL 0
#define ROAD 0

class MazeMap
{
public:
	MazeMap(char wall);
	~MazeMap();
	void setWallChar(char wall); //set map char
	void printMap();
	void setMap(int* map, int row,int col); //print map
	int** getMap(); //2D pointer
	void setExitPosition(COORD coo); // exit door
	COORD getExitPosition(); 
private:
	char m_cWall; // char wall
	char m_cRoad; // cahr road
	int** m_pMap;
	int m_iMapRow;
	int m_iRoadCol;
	COORD m_ExitPosition;

};

#endif