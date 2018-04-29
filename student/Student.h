#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	Student();
	Student(string name, float score=60.5);
	//Student(string name="Lucy", float score=60.5);
	~Student();

	void setName(std::string name);
	std::string getName();

	void setGender(std::string gender);
	std::string getGender();

	void initScore();
	void study(float score);
	float getScore();
private:
	string m_strName;
	string m_strGender;
	float m_fScore;
};