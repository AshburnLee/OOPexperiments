#include"Account.h"
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;

//***********************************************
//      function declaration
//***********************************************
void intro();
void writeAccount();
void displayAll();
void displayBalance(int);
void deleteAccount(int);
void modifyAccount(int);
void depositWithdraw(int, int);
//***********************************************
//      the main function of this program 
//***********************************************
int main(int argc, char const *argv[])
{
    char choose;
    int num;
    /* Intro infomation */
    intro();

    do{
        cout<<"\nMAIN MENU";
        cout<<"\n\t01. NEW ACCOUNT";
		cout<<"\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\t04. BALANCE ENQUIRY";
		cout<<"\n\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\t06. CLOSE AN ACCOUNT";
		cout<<"\n\t07. MODIFY AN ACCOUNT";
		cout<<"\n\t08. EXIT";
		cout<<"Select Your Option (1-8) ";
        cin>>choose; // choose services
        switch(choose)
        {
        case '1':
            writeAccount();  //write into storage
            break;
        case '2':
            cout<<"\n\nEnter the account No.:";
            cin>>num;
            depositWithdraw(num, 1); //
            break;
        case '3':
            cout<<"\n\nEnter the account No.:";
            cin>>num;
            depositWithdraw(num, 2); //
            break;
        case '4':
            cout<<"\n\n\tEnter thr account No.:";
            cin>>num;
            displayBalance(num);
            break;
        case '5':
            displayAll();
            break;
        case '6':
            cout<<"\n\n\tEnter your account No.:";
            cin>>num;
            deleteAccount(num);
            break;
        case '7':
            cout<<"Enter your account number:";
            cin>>num;
            modifyAccount(num);
            break;
        case '8':
            cout<<"Thanks fot using this system";
            break;
        default:cout<<"\a";
        }
        cin.ignore();
        cin.get();
    }while(choose!='8');
    return 0;
}

//***********************************************
//      1 create a new account and writ eit to starge
//***********************************************
void writeAccount()
{
    Account acc;   // instantiate a Account
    ofstream outFile; // instantiate a file
    outFile.open("account.dat", ios::binary | ios::app);
    acc.create_account();
    outFile.write(reinterpret_cast<char *>(&acc), sizeof(Account));
    outFile.close();
}

//***********************************************
//      2,3 Change balance
//***********************************************
void depositWithdraw(int accountNumber, int option)
{
    int amt;
    bool found = false;
    Account acc;
    fstream File;
    File.open("account.dat",ios::binary | ios::in | ios::out);
    if(!File){
        cout<<"File could not be open..";
        return;
    }
    while(!File.eof() && found==false){
        File.read(reinterpret_cast<char *>(&acc),sizeof(Account));
        if(acc.returnAccountNum()==accountNumber){
            acc.show_account();
            if(option==1){
                cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited";
				cin>>amt;
				acc.dep(amt); //add amt
            }
            if(option==2){
                cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw";
				cin>>amt;
				int bal=acc.returnDeposit()-amt;
				if((bal<500 && acc.returnType()=='S') || (bal<1000 && acc.returnType()=='C'))
					cout<<"Insufficience balance";
				else
					acc.draw(amt); //substract amt

            }
            int pos=(-1)*static_cast<int>(sizeof(acc));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *>(&acc),sizeof(Account));
            cout<<"\n\n\tRecord Updated";
            found=true;
        }
    }
    File.close();
    if(found==false){
        cout<<"\n\n Record not found";
    }
}


//***********************************************
//      4 Display balance
//***********************************************
void displayBalance(int accountNumber)
{
    Account acc;
    bool flag= false;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile){
        cout<<"File counld not be open!";
        return;
    }
    cout<<"Balance detatils\n";

    while(inFile.read(reinterpret_cast<char *>(&acc), sizeof(Account))){
        if(acc.returnAccountNum() == accountNumber){
            acc.show_account(); 
            flag=true;
        }
    }
    inFile.close();
    if(flag==false){
        cout<<"\nAccount number does not exits";
    }
}

//***********************************************
//       5 display all account information
//***********************************************
void displayAll()
{
    Account acc;
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile){
        cout<<"File could not be open..";
        return;
    }
    cout<<"\n\n\t\tACCOUNT HANDLER LIST\n\n";
    cout<<"=================================================\n";
    cout<<"A/c no.         NAME          TYPE       Balance\n";
    cout<<"=================================================\n";
    while(inFile.read(reinterpret_cast<char *> (&acc), sizeof(Account))){
        acc.report();
    }
    inFile.close();

}

//***********************************************
//      6 Close an account
//***********************************************
void deleteAccount(int accountNumber)
{
    Account acc;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile){
        cout<<"File counld not be open!";
        return;
    }
    outFile.open("temp.dat",ios::binary);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *>(&acc),sizeof(Account))){
        if(acc.returnAccountNum()==accountNumber){
            outFile.write(reinterpret_cast<char *>(&acc),sizeof(Account));
        }
    }
    inFile.close();
    outFile.close();
    remove("account.dat");
    rename("temp.dat","account.dat");
    cout<<"Record deleted..";

}

//***********************************************
//      7 Modify an account
//***********************************************
void modifyAccount(int accountNumber)
{
    bool flag = false;
    Account acc;
    fstream File;
    File.open("account.dat",ios::binary | ios::in | ios::out);
    if(!File){
        cout<<"File counld not be open!";
        return;
    }
    while(!File.eof() && flag==false){
        File.read(reinterpret_cast<char *>(&acc),sizeof(Account));
        if(acc.returnAccountNum() == accountNumber){
            acc.show_account();
            cout<<"\nEnter teh detail of account\n";
            acc.modify();
            int pos=(-1)*static_cast<int>(sizeof(Account));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *>(&acc),sizeof(Account));
            cout<<"\n\n\t Record Updated";
            flag=true;
        }
    }
    File.close();
    if(flag==false){
        cout<<"\n\n Record not found";
    }
}

//***********************************************
//      INTRODUCTION FUNCTION
//***********************************************
void intro()
{
    cout<<"\n\n\tBANK";
    cout<<"\n\n\tMANAGEMENT";
    cout<<"\n\n\tSYSTEM";
    cout<<"\n\n\n\nMADE BY: Junhui li";
    cout<<"\n\nORGANIZATION: University of Leeds";
    cin.get(); // keep the console open
}