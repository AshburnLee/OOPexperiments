#ifndef ACCOUNT_H
#define ACCOUNT_H

using namespace std;

class Account
{
    int accNum;
    char name[50];
    int deposit;
    char type;
public:
    void create_account(); // create account in memory
    void show_account() const; //show account
    void modify(); //add new dsata
    void dep(int); //add money
    void draw(int); //withdraw money
    void report() const; //show detail
    int returnAccountNum() const; //return account num
    int returnDeposit() const; //return balance amount 
    char returnType() const; //return type of account
};

#endif