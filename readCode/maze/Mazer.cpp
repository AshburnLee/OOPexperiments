#include"Mazer.h"
#include<windows.h>

Mazer::Mazer()
{
	m_iSteps = 0;
}

void Mazer::moveForward(char direction)
{
	unsigned long numWritten;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	FillConsoleOutputCharacter(handle, ' ', 1, m_heroCurrentPosition,&numWritten);

	switch (direction)
	{
	case 'U':
		m_heroCurrentPosition.Y -= 1;
		break;
	case 'R':
		m_heroCurrentPosition.X += 1;
		break;
	case 'D':
		m_heroCurrentPosition.Y += 1;
		break;
	case 'L':
		m_heroCurrentPosition.X -= 1;
		break;
	default:
		break;
	}
	//coord is updated 
	FillConsoleOutputCharacter(handle, m_cHero, 1, m_heroCurrentPosition, &numWritten);
	//update the dirtection 
	m_cHeroLookAt = direction;	
}

bool Mazer::walkUp()
{
	if(m_pMap->getMap()[m_heroCurrentPosition.Y-1][m_heroCurrentPosition.X]){
		return false;
	}
	else{
		moveForward('U');
		return true;
	}
}
bool Mazer::walkDown()
{
	if(m_pMap->getMap()[m_heroCurrentPosition.Y+1][m_heroCurrentPosition.X]){
		return false;
	}
	else{
		moveForward('D');
		return true;
	}
}
bool Mazer::walkRight()
{
	if(m_pMap->getMap()[m_heroCurrentPosition.Y][m_heroCurrentPosition.X-1]){
		return false;
	}
	else{
		moveForward('L');
		return true;
	}
}
bool Mazer::walkLeft()
{
	if(m_pMap->getMap()[m_heroCurrentPosition.Y][m_heroCurrentPosition.X+1]){
		return false;
	}
	else{
		moveForward('R');
		return true;
	}
}

//current facing direction:
void Mazer::setDirection(char direction)
{
	m_cHeroLookAt = direction;
}

//set position
void Mazer::setPosition(int x, int y)
{
	unsigned long numWritten;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	m_heroCurrentPosition.X = x;
	m_heroCurrentPosition.Y = y;
	FillConsoleOutputCharacter(handle, m_cHero, 1, m_heroCurrentPosition, &numWritten); 
}

void Mazer::setHero(char hero)
{
	m_cHero = hero;
}
void Mazer::setMap(MazeMap* map)
{
	m_pMap = map;
}
int Mazer::getSteps()
{
	return m_iSteps;
}

//游戏开始函数
void Mazer::start()
{
	while (true)
	{
		switch (m_cHeroLookAt)
		{
		case 'U':
			//游戏角色朝上时，优先向右走，其次向上走，再次向走左，最次向下走（右手原则）
			walkRight() || walkUp() || walkLeft() || walkDown();
			break;
		case 'D':
			//同样是右手原则，由于此时游戏角色朝下，所以此时游戏角色的右是电脑屏幕的左，其他方向依次类推
			walkLeft() || walkDown() || walkRight() || walkUp();
			break;
		case 'R':
			//还是右手原则，由于此时游戏角色朝右，所以此时游戏角色的右是电脑屏幕的下，其他方向依次类推
			walkDown() || walkRight() || walkUp() || walkLeft();
			break;
		case 'L':
			//也是右手原则，由于此时游戏角色朝左，所以此时游戏角色的右是电脑屏幕的上，其他方向依次类推
			walkUp() || walkLeft() || walkDown() || walkRight();
			break;
		default:
			break;
		}
		m_iSteps++;
		//判断游戏角色的当前位置是否是迷宫出口位置，如果到达出口，游戏结束
		if (m_heroCurrentPosition.X == m_pMap->getExitPosition().X && m_heroCurrentPosition.Y == m_pMap->getExitPosition().Y)
		{
			break;
		}
		//为了使游戏角色的移动过程可见，所以每走一步，要歇息一段时间(Sleep函数传入参数的单位是毫秒)
		Sleep(500);
	}
}
