#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
using namespace std;

class StudentRecord
{
    int _rollNumber;
    char _name[50];
    int _pMarks, _cMarks, _mMarks, _eMarks, _csMarks;
    double _averageMarks;
    char _grade;
    void calculate();
public:
    void getData();
    void showData() const;
    void showRecord() const;
    int returnRollNumber() const;
};



#endif