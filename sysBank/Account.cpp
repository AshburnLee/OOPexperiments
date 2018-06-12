#include"Account.h"
#include<iostream>
#include<iomanip>
using namespace std;

void Account::create_account()
{
    cout<<"\nEnter the Account No. :";
    cin>>accNum;
    cout<<"\n\nEnter the name of the account holder :";
    cin.ignore();
    cin.getline(name, 50);
    cout<<"\nEnter the type of account (C/S) :";
    cin>>type;
    type=toupper(type);
    cout<<"\nEnter the initial amount :";
    cin>>deposit;
    cout<<"\n\n\nAccount Created...\n";
}

void Account::show_account() const
{
    cout<<"\nAccount No.: "<<accNum;
    cout<<"\nAccount Holder Name : ";
    cout<<name;
    cout<<"\nType of Account :"<<type;
    cout<<"\nBalance Amount :"<<deposit;
}

void Account::modify()
{
    cout<<"\nAccount No.: "<<accNum;
    cout<<"\nModify Account Holder Name:";
    cin.ignore();
    cin.getline(name,50);
    cout<<"Modify Type of Account:";
    cin>>type;
    type=toupper(type);
    cout<<"\nModify Balance Amount:";
    cin>>deposit;
}

void Account::dep(int x)
{
    deposit+=x;
}
void Account::draw(int x)
{
    deposit-=x;
}
void Account::report() const
{   // std::setw set field width
    cout<<accNum<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(10)<<deposit<<endl; 
}
int Account::returnAccountNum() const
{
    return accNum;
}
int Account::returnDeposit() const
{   
    return deposit;
}
char Account::returnType() const
{
    return type;
}