#include"Bank.h"
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>  //usleep()
using namespace std;

long int randomNumber = 12989;

void Bank::openNewAccount()
{
    cin.ignore();
    cout<<"\nEnter your name: ";
    getline(cin, name);
    cout<<"\nEnter your address: ";
    getline(cin, address);
    cout<<"\nEnter your mobile: ";
    getline(cin,mobileNumber);
    cout<<"\nEnter your email address:";
    getline(cin, email);
    cout<<"\nCongratulation, a new account has been regestered in the system."<<endl;
    accountNumber = randomNumber;
    cout<<name<<"has been regestered with the following account number: "<<accountNumber<<endl;
    randomNumber++;
    usleep(20000);
    char a='\0';
    cout<<"Enter any alphanumeric to return to the main menu..."<<endl;
    cin>>a;
    return; 
}

/*
*类的友元函数是定义在类外部，
*但有权访问类的所有私有（private）成员和保护（protected）成员。
*尽管友元函数的原型有在类的定义中出现过，但是友元函数并不是成员函数。
* So void Bank::showAllAccountInfo() is incorrect!!!!!!!!!!
*/
void showAllAccountInfo(Bank obj[], int i)
{
    if(i==0){
        cout<<"No account registered i nthe bank"<<endl;
        return;
    }
    int index;
    for(index=1; index<=i; index++){
        cout<<"\nAccount number "<<index<<endl;
        cout<<"Name: "<<obj[index].name<<\
        "\nAccount number: "<<obj[index].accountNumber<<\
        "\nAddress: "<<obj[index].address<<\
        "\nE-mail: "<<obj[index].email<<\
        "\nMobile number: "<<obj[index].mobileNumber<<\
        "\nBalance: "<<obj[index].balance<<endl<<endl;
    }usleep(20000);
    char a='\0';
    cout<<"Enter any alpha to return to main menu..."<<endl;
    cin>>a;
    return;
}

void showAnAccountInfo(Bank obj[], int i)
{
    if(i==0){
        cout<<"No such an account..."<<endl;
        return;
    }
    long int check;
    long int verified;
    int index=1;
    int flag=0;
    cout<<"\nEnter Account Number to display the details: ";
    cin>>check;
    for (index=1;index<=i; index++){
        if(obj[index].accountNumber == check){
            flag=1;
            verified=index;
        }
    }
    if (flag==1){
        cout<<"Name: "<<obj[verified].name<<\
        "\nAccount number: "<<obj[verified].accountNumber<<\
        "\nAddress: "<<obj[verified].address<<\
        "\nE-mail: "<<obj[verified].email<<\
        "\nMobile number: "<<obj[verified].mobileNumber<<\
        "\nBalance: "<<obj[verified].balance<<endl<<endl;
    }else{
        cout<<"This account has not been registered"<<endl;
        return;
    }
    usleep(20000);
    char a= '\0';
    cout<<"Enter any alpha to return to the manue..."<<endl;
    cin>>a;
    return;

}

void withDraw(Bank obj[], int i)
{
    //*************************************
    //    iter every record in the obj list
    //*************************
    if(i==0){
        cout<<"No such an account..."<<endl;
        return;
    }
    long int check,verified;
    int index, flag=0;
    cout<<"\nEnter the account number to withdraw: ";
    cin>>check;
    for(index=1; index<=i; index++){
        if(obj[index].accountNumber==check){
            flag=1;
            verified=index;
        }
    }

    // if the account exits: do 
    if(verified==1){
        if(obj[verified].balance == 0){
            cout<<"\nAccount has insufficient balance"<<endl;
            return;
        }
        cout<<"Enter the amount to be withdraw: ";
        long double amount;
        cin>>amount;
        if(amount>=obj[verified].balance){
            cout<<\
            "\nBalance is insufficient for that amount of \
            withdrawal.\nBalance: "<<obj[verified].balance<<\
            "\nAmount Entered: "<<amount<<endl<<endl;
            return;
        }
        obj[verified].balance -= amount;
        cout<<"Balance after withdraw: "<<obj[verified].balance<<endl;
    }
    else{
        cout<<"The account number was not registered"<<endl<<endl;
        return;
    }
    usleep(20000);
    char a= '\0';
    cout<<"Enter any alphanumeric to return to main menu..."<<endl;
    cin>>a;
    return;

}

void deposit(Bank obj[],  int i)
{
    if(i==0){
        cout<<"\nNo account registered in the bank"<<endl<<endl;
        return;
    }
    long int check,verified;
    int index,flag=0;
    cout<<"\nEnter Account Number to deposit: ";
    cin>>check;
    for(index=1;index<=i;index++){
        if((obj[index].accountNumber) == check){
            flag=1;
            verified = index;
        }
    }
    if(flag==1){
        cout<<"Enter the account number of the account";
        long double amount;
        cin>>amount;
        obj[verified].balance += amount;
        cout<<"Balance after money deposition: "<<obj[verified].balance<<endl;

    }else{
        cout<<"The account number was not registered"<<endl<<endl;
        return;
    }
    usleep(20000);
    char a='\0';
    cout<<"Enter the alpha to return the main menu.."<<endl;
    cin>>a;
    return;

}

void showBalanceInfo(Bank obj[], int i)
{
    if(i==0){
        cout<<"\nNo account registered in the bank"<<endl<<endl;
        return;
    }
    long int check,verified;
    int index,flag=0;
    cout<<"\nEnter Account Number: ";
    cin>>check;
    for(index=1;index<=i;index++){
        if((obj[index].accountNumber)==check){
            flag=1;
            verified = index;
        }
    }

    if(flag==1)
    {
        cout<<"Balance for "<<obj[verified].name<<\
        " is "<<obj[verified].balance<<endl<<endl;
    }
    else
    {
        cout<<"The account number was not registered"<<endl<<endl;
        return;
    }
    usleep(200000);
    char a='\0';
    cout<<"Enter any alphanumeric to return to main menu..."<<endl;
    cin>>a;
    return;
}
