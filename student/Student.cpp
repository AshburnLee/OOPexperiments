#include<iostream>
#include<string>
#include"Student.h"
using namespace std;

Student::Student():m_strName("Logon"),m_fScore(70.8){
	//  default  initialis:
	//m_strName = "Logon";
	//m_fScore = 70.8;
	cout<<"Student()"<<endl;
}

Student::Student(string name, float score):m_strName(name),m_fScore(score)
{
	cout<<"Student(strng name, float score)"<<endl;
}

Student::~Student(){
	cout<<"~Student()"<<endl;
}

void Student::setName(string name){
	m_strName = name;
}

string Student::getName(){
	return m_strName;
}

void Student::setGender(string gender){
	m_strGender = gender;
}

string Student::getGender(){
	return m_strGender;
}

void Student::initScore(){
	m_fScore = 0.0;
}
void Student::study(float score){
	m_fScore += score;
}
float Student::getScore(){
	return m_fScore;
}
