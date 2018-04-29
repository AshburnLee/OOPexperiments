#include<string>

using namespace std;

class Person
{
public:
	Person();
	~Person();
	int eat(int );
	void play();
protected:
	string m_strName;
};
