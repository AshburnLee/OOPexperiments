#include"StudentRecord.h"
#include<iostream>
#include<iomanip>

void StudentRecord::calculate()
{
    _averageMarks = (_pMarks+_cMarks+_mMarks+_eMarks+_csMarks)/5;
    if(_averageMarks>=60){
        _grade='A';
    }else if(_averageMarks>=50){
        _grade='B';
    }else if(_averageMarks>=33){
        _grade='C';
    }else{
        _grade='F';
    }
}

void StudentRecord::getData()
{
    cout<<"\nEnter The Roll Number of Student:";
    cin>>_rollNumber;
	cout<<"\n\nEnter The Name of student ";
	cin.ignore();
	cin.getline(_name,50);
	cout<<"\nEnter The marks in physics out of 100 : ";
	cin>>_pMarks;
	cout<<"\nEntevoide marks in chemistry out of 100 : ";
	cin>>_cMarks;
	cout<<"\nEntevoide marks in maths out of 100 : ";
	cin>>_mMarks;
	cout<<"\nEnter The marks in english out of 100 : ";
	cin>>_eMarks;
	cout<<"\nEnter The marks in computer science out of 100 : ";
	cin>>_csMarks;
	calculate();
}

void StudentRecord::showData() const
{
    cout<<"\nRoll number of student : "<<_rollNumber;
	cout<<"\nName of student : "<<_name;
	cout<<"\nMarks in Physics : "<<_pMarks;
	cout<<"\nMarks in Chemistry : "<<_cMarks;
	cout<<"\nMarks in Maths : "<<_mMarks;
	cout<<"\nMarks in English : "<<_eMarks;
	cout<<"\nMarks in Computer Science :"<<_csMarks;
	cout<<"\nPercentage of student is  :"<<_averageMarks;
	cout<<"\nGrade of student is :"<<_grade<<endl;
}
void StudentRecord::showRecord() const
{
    cout<<"\n"<<_rollNumber<<setw(6)<<" "<<_name<<setw(10)\
	<<_pMarks<<setw(4)<<_cMarks<<setw(4)\
	<<_mMarks<<setw(4)<<_eMarks<<setw(4)\
	<<_csMarks<<setw(8)<<_averageMarks<<setw(6)<<_grade<<endl<<endl;
}
int StudentRecord::returnRollNumber() const
{
    return _rollNumber;
}
