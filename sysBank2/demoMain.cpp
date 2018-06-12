#include"Bank.h"
#include<string.h>
#include<unistd.h>
#include<iostream>
#include<stdlib.h>
using namespace std; 

int main(int argc, char const *argv[])
{
    int choice;
    int i=0;
    string password = "1234";
    string input;
    Bank obj[100];
    cout<<"Enter root password:";
    cin>>input;
    //system("CLS");
    if(input.compare(password)==0){
        cout<<"Bank System Loading menu...."<<endl;
        usleep(20000);
        do{
            usleep(20000);
            cout<<"\nEnter your choice: ";
            cout<<"\n1.Open an account ";
            cout<<"\n2.List all accounts ";
            cout<<"\n3.List the detail for a user ";
            cout<<"\n4.Withdraw from saving ";
            cout<<"\n5.Deposit into account ";
            cout<<"\n6.List the balance of user ";
            cout<<"\n9.Exit the software";
            cin>>choice;
            switch(choice){
                case 1:
                    i++;
                    obj[i].openNewAccount();
                    break;
                case 2:
                    showAllAccountInfo(obj, i);
                    break;
                case 3:
                    showAnAccountInfo(obj,i);
                    break;
                case 4:
                    withDraw(obj, i);
                    break;
                case 5:
                    deposit(obj, i);
                    break;
                case 6:
                    showBalanceInfo(obj, i);
                    break;
                case 9:
                    break;
                default:
                    cout<<"\nInvalid input"<<endl;
            }

        }while(choice!=9);

    }else{
        cout<<"Root access not granted"<<endl;
    }
    return 0;
}
