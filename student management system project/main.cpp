#include<iostream>
#include<fstream>
#include<cstdlib>
#include<conio.h>
using namespace std;

class student{
    string name, roll_no, course, email, address, mobile; 
    public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void delete_s();
};

void student::menu(){
    while(true){
        int choice;
        char x;
        system("cls");

        cout<<"\t\t\t\t\t-----------------------------"<<endl;
        cout<<"\t\t\t\t\t| STUDENT MANAGEMENT SYSTEM |"<<endl;
        cout<<"\t\t\t\t\t-----------------------------"<<endl<<endl;

        cout<<"\t\t\t\t\t1. Enter new record"<<endl;
        cout<<"\t\t\t\t\t2. Display record"<<endl;
        cout<<"\t\t\t\t\t3. Search record"<<endl;
        cout<<"\t\t\t\t\t4. Modify record"<<endl;
        cout<<"\t\t\t\t\t5. Delete record"<<endl;
        cout<<"\t\t\t\t\t6. Exit"<<endl<<endl;

        cout<<"\t\t\t\t\t-----------------------------"<<endl;
        cout<<"\t\t\t\t\t-ENTER CHOICE: [1/2/3/4/5/6]-"<<endl;
        cout<<"\t\t\t\t\t-----------------------------"<<endl<<endl;

        cout<<"\t\t\t\t\tYOUR CHOICE: ";
        cin>>choice;
        switch(choice){
            case 1:
            do{
                insert();
                cout<<"\t\t\t\t\tAdd another student[y/n]: ";
                cin>>x;
            }while(x=='y'||x=='Y');
            break;
            case 2:
            display();
            break;
            case 3:
            search();
            break;
            case 4:
            modify();
            break;
            case 5:
            delete_s();
            break;
            case 6:
            exit(0);
            break;
            default:
            cout<<endl<<"\t\t\t\t\tInvalid choice...."<<endl;
            break;
        }
        cout<<"\t\t\t\t\t press any key...."<<endl;
        getch();
    }
}

void student::insert(){
    system("cls");
    fstream file;
    cout<<"\t\t\t---------------------------ADD DETAILS---------------------------"<<endl;
    cout<<"\t\t\t-----------------------------------------------------------------"<<endl<<endl;
    cout<<"\t\t\t\t\t1. Student's name: ";
    cin.ignore();
    getline(cin, name);
    cout<<"\t\t\t\t\t2. Roll number: ";
    cin>>roll_no;
    cout<<"\t\t\t\t\t3. Course: ";
    cin>>course;
    cout<<"\t\t\t\t\t4. Email address: ";
    cin>>email;
    cout<<"\t\t\t\t\t5. Residential address: ";
    cin>>address;
    cout<<"\t\t\t\t\t6. Mobile number: ";
    cin>>mobile;
    cout<<endl;
    file.open("student record.txt", ios::app);
    file<<name<<" "<<roll_no<<" "<<course<<" "<<email<<" "<<address<<" "<<mobile<<endl;
    file.close();
}

void student::display(){
    system("cls");
    fstream file;
    cout<<"\t\t\t-------------------------SHOWING RECORDS-------------------------"<<endl;
    cout<<"\t\t\t-----------------------------------------------------------------"<<endl<<endl;

    file.open("student record.txt", ios::in);
    int count=1;
    if(!file.is_open()){
        cout<<"record is empty......."<<endl;
        file.close();
    }
    else{
        string first, last;
        file>>first>>last>>roll_no>>course>>email>>address>>mobile;
        while(!file.eof()){
            name=first+" "+last;
            cout<<"\t\t\t\t\tstudent no. "<<count++<<endl;
            cout<<"\t\t\t\t\tstudent's name: "<<name<<endl;
            cout<<"\t\t\t\t\tstudent's roll no.: "<<roll_no<<endl;
            cout<<"\t\t\t\t\tstudent's course: "<<course<<endl;
            cout<<"\t\t\t\t\tstudent's email: "<<email<<endl;
            cout<<"\t\t\t\t\tstudent's address: "<<address<<endl;
            cout<<"\t\t\t\t\tstudent's mobile: "<<mobile<<endl<<endl;
            file>>first>>last>>roll_no>>course>>email>>address>>mobile;
        }
        file.close();
        if(count==1){
            cout<<"record is empty......."<<endl;
        }
    }
}

void student::modify(){
    system("cls");
    cout<<"\t\t\t---------------------------MODIFY RECORDS---------------------------"<<endl;
    cout<<"\t\t\t--------------------------------------------------------------------"<<endl<<endl;
    fstream readfile, writefile;
    readfile.open("student record.txt", ios::in);
    if(!readfile){
        cout<<"\t\t\t\trecord is empty......."<<endl;
        readfile.close();
    }
    else{
        string temproll, first, last;
        bool flag=0;
        cout<<"\t\t\t\tEnter the roll number of student you want to modify: ";
        cin>>temproll;
        writefile.open("record.txt", ios::app);
        readfile>>first>>last>>roll_no>>course>>email>>address>>mobile;
        while(!readfile.eof()){
            if(roll_no==temproll){
                cout<<"\t\t\t\t------------CURRENT RECORD------------"<<endl;
                cout<<"\t\t\t\t\tstudent's name: "<<first<<" "<<last<<endl;
                cout<<"\t\t\t\t\tstudent's roll no.: "<<roll_no<<endl;
                cout<<"\t\t\t\t\tstudent's course: "<<course<<endl;
                cout<<"\t\t\t\t\tstudent's email: "<<email<<endl;
                cout<<"\t\t\t\t\tstudent's address: "<<address<<endl;
                cout<<"\t\t\t\t\tstudent's mobile: "<<mobile<<endl<<endl;
                cout<<"\t\t\t\t------------SET NEW RECORD------------"<<endl;
                cout<<"\t\t\t\t\tStudent's name: ";
                cin.ignore();
                getline(cin, name);
                // cout<<"\t\t\t\t\t2. Roll number: ";
                // cin>>roll_no;
                cout<<"\t\t\t\t\tCourse: ";
                cin>>course;
                cout<<"\t\t\t\t\tEmail address: ";
                cin>>email;
                cout<<"\t\t\t\t\tResidential address: ";
                cin>>address;
                cout<<"\t\t\t\t\tMobile number: ";
                cin>>mobile;
                writefile<<name<<" "<<roll_no<<" "<<course<<" "<<email<<" "<<address<<" "<<mobile<<endl;
                readfile>>first>>last>>roll_no>>course>>email>>address>>mobile;
                flag=1;
                continue;
            }
            writefile<<first<<" "<<last<<" "<<roll_no<<" "<<course<<" "<<email<<" "<<address<<" "<<mobile<<endl;
            readfile>>first>>last>>roll_no>>course>>email>>address>>mobile;
        }
        readfile.close();
        writefile.close();
        if(flag){
            cout<<"\t\t\t\t\trecord modified successfully........."<<endl;
        }
        else{
            cout<<"\t\t\t\t\tNo record found........"<<endl;
        }
        remove("student record.txt");
        rename("record.txt", "student record.txt");
    }
}

void student::search(){
    system("cls");
    cout<<"\t\t\t---------------------------SEARCH RECORDS---------------------------"<<endl;
    cout<<"\t\t\t--------------------------------------------------------------------"<<endl<<endl;
    fstream file;
    file.open("student record.txt", ios::in);
    if(!file){
        cout<<"\t\t\t\tNo record found.........."<<endl;
        file.close();
    }
    else{
        string temproll, first, last;
        bool flag=0;
        cout<<"\t\t\t\tEnter the roll number of student you want to find: ";
        cin>>temproll;
        file>>first>>last>>roll_no>>course>>email>>address>>mobile;
        while(!file.eof()){
            if(roll_no==temproll){
                cout<<"\t\t\t\t------------RECORD FOUND------------"<<endl;
                cout<<"\t\t\t\t\tstudent's name: "<<first<<" "<<last<<endl;
                cout<<"\t\t\t\t\tstudent's roll no.: "<<roll_no<<endl;
                cout<<"\t\t\t\t\tstudent's course: "<<course<<endl;
                cout<<"\t\t\t\t\tstudent's email: "<<email<<endl;
                cout<<"\t\t\t\t\tstudent's address: "<<address<<endl;
                cout<<"\t\t\t\t\tstudent's mobile: "<<mobile<<endl<<endl;
                flag=1;
                break;
            }
            file>>first>>last>>roll_no>>course>>email>>address>>mobile;
        }
        if(!flag){
            cout<<"\t\t\t\t\tNo record found........"<<endl;
        }
        file.close();
    }
}

void student::delete_s(){
    system("cls");
    cout<<"\t\t\t---------------------------DELETE RECORDS---------------------------"<<endl;
    cout<<"\t\t\t--------------------------------------------------------------------"<<endl<<endl;
    fstream readfile, writefile;
    readfile.open("student record.txt", ios::in);
    if(!readfile){
        cout<<"\t\t\t\trecord is empty......."<<endl;
        readfile.close();
    }
    else{
        string temproll, first, last;
        bool flag=0;
        cout<<"\t\t\t\tEnter the roll number of student you want to delete: ";
        cin>>temproll;
        writefile.open("record.txt", ios::app);
        readfile>>first>>last>>roll_no>>course>>email>>address>>mobile;
        while(!readfile.eof()){
            if(roll_no==temproll){
                flag=1;
                readfile>>first>>last>>roll_no>>course>>email>>address>>mobile;
                continue;
            }
            writefile<<first<<" "<<last<<" "<<roll_no<<" "<<course<<" "<<email<<" "<<address<<" "<<mobile<<endl;
            readfile>>first>>last>>roll_no>>course>>email>>address>>mobile;
        }
        readfile.close();
        writefile.close();
        if(flag){
            cout<<"\t\t\t\t\trecord deleted successfully........."<<endl;
        }
        else{
            cout<<"\t\t\t\t\tNo record found........"<<endl;
        }
        remove("student record.txt");
        rename("record.txt", "student record.txt");
    }
}

int main()
{
    student project;
    project.menu();
    return 0;
}