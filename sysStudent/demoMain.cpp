#include<iostream>
#include<fstream>
#include<iomanip>
#include"StudentRecord.h"


void writeStudent();
void readAllStudent();
void readSpecificRecord(int);
void deleteStudent(int);
void displayRecord();
void modifyStudent(int);
void intro();
void entryMenu();
void clearAll();

int main(int argc, char const *argv[])
{
    char choice;
    cout.setf(ios::fixed|ios::showpoint); //
    cout<<setprecision(2); //
    intro();
    do{
        cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t1. SHOW RESULT";
        cout<<"\n\n\t2. ENTERY MENU";
        cout<<"\n\n\t3. EXIT";
        cout<<"\n\n\t4. REMOVE ALL RECORDS **";
        cout<<"\n\n\tPlease select your option:  ";
        cin>>choice;
        switch(choice){
            case '1': 
                displayRecord();  // display all result
                break;
            case '2':
                entryMenu();  // enter main menu
                break;
            case '3':
                break;
            case '4':
                clearAll();
            default:
                cout<<"\a";
        }
    }while(choice!='3');
    return 0;
}

// write data into file
void writeStudent()
{
    StudentRecord student;
    ofstream outFile;
    student.getData();   // input infomation 
    outFile.open("data.dat",ios::binary | ios::app);
    outFile.write(reinterpret_cast<char *> (&student),sizeof(StudentRecord));
    outFile.close();
    cout<<"\n\nStudent record has been created..";
    cin.ignore();
    cin.get();
}

void readAllStudent()
{
    StudentRecord student;
    ifstream inFile;
    inFile.open("data.dat", ios::binary);
    if(!inFile){
        cout<<"File counld not been open !!";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\t\tDisplay All Records!!\n\n";
    while(inFile.read(reinterpret_cast<char *>(&student),sizeof(StudentRecord))){
        student.showData(); //show information
        cout<<"\n\n==================================\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void readSpecificRecord(int n)
{
    StudentRecord student;
    ifstream inFile;
    inFile.open("data.dat",ios::binary);
    if(!inFile){
        cout<<"File counld not been open !!";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag = false;
    while(inFile.read(reinterpret_cast<char *>(&student),sizeof(StudentRecord))){
        if(student.returnRollNumber() == n){
            student.showData();
            flag = true;
        }
    }
    inFile.close();
    if(flag==false){
        cout<<"\n\nRecord not exist..";
    }
    cin.ignore();
    cin.get();
}

void deleteStudent(int n)
{
    StudentRecord student;
    ifstream inFile;
    inFile.open("data.dat",ios::binary);
    if(!inFile){
        cout<<"File could not be open!!";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("tmp.dat",ios::binary);
    inFile.seekg(0,ios::beg);  // file pointer
    while(inFile.read(reinterpret_cast<char *>(&student),sizeof(StudentRecord))){
        if(student.returnRollNumber()!=n){
            outFile.write(reinterpret_cast<char *>(&student),sizeof(StudentRecord));
        }
    }
    outFile.close();
    inFile.close();
    remove("data.dat");
    rename("tmp.dat","data.dat");
    cout<<"\n\n\tRecord deleted ..";
    cin.ignore();
    cin.get();
}

void displayRecord()
{
    StudentRecord student;
    ifstream File;
    File.open("data.dat",ios::binary);
    if(!File){
        cout<<"File could not be open";
        cin.ignore();
        cin.get();
    }
    cout<<"\n\n\t\tALL STUDENT RESULTS\n\n";
    cout<<"=================================================================\n";
    cout<<"R.No      name      P    c    m    e    cs    Average    Grade"<<endl;
    cout<<"=================================================================\n";
    while(File.read(reinterpret_cast<char *>(&student), sizeof(StudentRecord))){
        student.showRecord();
    }
    cin.get();
    cin.ignore();
    File.close();
}

void modifyStudent(int n)
{
    bool found = false;
    StudentRecord student;
    fstream File;
    File.open("data.dat",ios::binary|ios::in|ios::out);
    if(!File){
        cin.ignore();
        cin.get();
        return;
    }
    while(!File.eof() && found == false){
        File.read(reinterpret_cast<char *>(&student),sizeof(StudentRecord));
        if(student.returnRollNumber()==n){
            student.showData();
            cout<<"\n\nPlease Enter teh new details of student: "<<endl;
            student.getData();
            int pos=(-1)*static_cast<int>(sizeof(StudentRecord));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *>(&student),sizeof(StudentRecord));
            cout<<"\n\n Record Updated";
            found=true;
        }
    }
    File.close();
    if(found==false){
        cout<<"\n\n Record Not Found";
    }
    cin.ignore();
    cin.get();
}

void intro()
{
    cout<<"\n\n\n\t\t STUDENT";
    cout<<"\n\n\t\t REPORT CARD";
    cout<<"\n\n\t\t PROJECT";
    cout<<"\n\n\t\t MADE BY JUNHUI LI";
    cin.get();
}

void entryMenu()
{
    char choice;
    int number;
    cout<<"\n\n\n\tENTRY MENU";
    cout<<"\n\n\n\t1. CREATE STUDENT RECORD";
    cout<<"\n\n\n\t2. READ ALL RECORDS";
    cout<<"\n\n\n\t3. READ SPECIFIC RECORD";
    cout<<"\n\n\n\t4. MODIFY RECORD  ";
    cout<<"\n\n\n\t5. DELETE RECORD  ";
    cout<<"\n\n\n\t6. BACK TO MAIN MENU\n";
    cin>>choice;
    switch(choice)
    {
        case '1':
            writeStudent();
            break;
        case '2':
            readAllStudent();
            break;
        case '3':
            cout<<"Enter the roll numbe rof the student: ";cin>>number;
            readSpecificRecord(number);
            break;
        case '4':
            cout<<"Enter thr roll number to be modified: ";cin>>number;
            modifyStudent(number);
            break;
        case '5':
            cout<<"Enter the roll number to be deleted: ";cin>>number;
            deleteStudent(number);
            break;
        case '6':
            break;
        default:
            cout<<"\a";
            entryMenu();

    }
}

void clearAll()
{
    char choice;
    cout<<"\nAre ypu sure about that ?(y/n)";
    cin>>choice;
    switch(choice)
    {
        case 'y':
            remove("data.dat");
            break;
        case 'n':
            break;
        default:
            cout<<"\a";  //!!!!!!!!!
            entryMenu();
    }
}