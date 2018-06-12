#ifndef BANK_H
#define BANK_H
//**************************************
//    friend func not class member func
//**************************************
#include<string.h>
#include<iostream>
using namespace std;

class Bank
{
    string name;
    string address;
    string mobileNumber;
    string email;
    long double balance=0;
    long int accountNumber=0;
public:
    void openNewAccount();
    friend void showAllAccountInfo(Bank obj[], int i);
    friend void showAnAccountInfo(Bank obj[], int i);
    friend void withDraw(Bank obj[], int i);
    friend void deposit(Bank obj[], int i);
    friend void showBalanceInfo(Bank obj[], int i);
};

#endif