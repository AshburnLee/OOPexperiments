#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
public:
	Coordinate(int x, int y);
	~Coordinate();
	int getX();
	int getY();
private:
	int m_iX;
	int m_iY;
};

#endif