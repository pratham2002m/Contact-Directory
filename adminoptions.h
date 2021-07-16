#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<time.h>
#include<conio.h>

// #include "gotoxy.h"
#include "addcontact.h"
#include "updatecontact.h"
#include "removecontact.h" 
// #include "login.h"


void gotoxy1(short int x,short int y) // To Move The Cursor To The Desired Place
{
HANDLE Screen;
Screen = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Position={x, y};
SetConsoleCursorPosition(Screen, Position);
}



void adminoptions(){
    
    system("cls");
    SetConsoleTextAttribute(h,12); 
    gotoxy1(74,7);
    cout<<"Welcome To Contact Directory \n\n\n\n";
    SetConsoleTextAttribute(h,2);
    gotoxy1(30,10);
    cout<<"Choose your action : ";

    int action ;

    SetConsoleTextAttribute(h,14);
    gotoxy1(30,12);
    cout<<"1. Add a contact"<<endl;
    SetConsoleTextAttribute(h,3);
    gotoxy1(30,13);
    cout<<"2. Remove a contact"<<endl;
    SetConsoleTextAttribute(h,4);
    gotoxy1(30,14);
    cout<<"3. Update a contact ";
    SetConsoleTextAttribute(h,7);
    gotoxy1(30,16);
    cin>>action;

    SetConsoleTextAttribute(h,15);

    switch (action)
    {

    case 1:
        addcontact();
        break;
    
    case 2:
    {
        fflush(stdin);
        SetConsoleTextAttribute(h,12);
        gotoxy1(78,18);
        cout<<"REMOVE CONTACT FORM";
        string name,city,number;

        SetConsoleTextAttribute(h,14);
        gotoxy1(30,21);
        cout<<"Name of user : ";
        SetConsoleTextAttribute(h,15);
        getline(cin,name);

        fflush(stdin);
        SetConsoleTextAttribute(h,14);
        gotoxy1(30,23);
        cout<<"City : ";
        SetConsoleTextAttribute(h,15);
        getline(cin,city);

        fflush(stdin);
        SetConsoleTextAttribute(h,14);
        gotoxy1(30,25);
        cout<<"Mobile no : ";
        SetConsoleTextAttribute(h,15);
        cin>>number ;

        fflush(stdin);
        removecontact(name,city,number);

        break;
    }
    case 3:
    {
        int action ;

        SetConsoleTextAttribute(h,12);
        gotoxy(78,18);
        cout<<"UPDATE CONTACT FORM";

        gotoxy(30,21);
        SetConsoleTextAttribute(h,10);
        cout<<"Choose the format : "<<endl;
        SetConsoleTextAttribute(h,14);
        gotoxy(30,23);
        cout<<"1.Name";
        gotoxy(30,25);
        cout<<"2.Mobile No.";
        gotoxy(30,27);
        cout<<"3.Profession ";
        gotoxy(49,27);
        SetConsoleTextAttribute(h,15);
        cin>>action;

        SetConsoleTextAttribute(h,15);
   

        string oldname, newname, old_number, new_number, oldcity, newcity, old_address,new_address, old_profession, new_profession ;

        fflush(stdin);

        SetConsoleTextAttribute(h,11);
        gotoxy(30,29);
        cout<<"City : ";
        SetConsoleTextAttribute(h,15);
        getline(cin,oldcity);

        switch (action)
        {

        case 1:
            fflush(stdin);
            SetConsoleTextAttribute(h,2);
            gotoxy(30,31);
            cout<<"Old Name : ";
            SetConsoleTextAttribute(h,15);
            getline(cin,oldname);

            fflush(stdin);
            SetConsoleTextAttribute(h,2);
            gotoxy(30,33);
            cout<<"New Name : ";
            SetConsoleTextAttribute(h,15);
            getline(cin,newname);
            gotoxy(30,35);
            break;
        
       
        case 2:
            fflush(stdin);
            SetConsoleTextAttribute(h,2);
            gotoxy(30,31);
            cout<<"Old Mobile No : ";
            SetConsoleTextAttribute(h,15);
            getline(cin,old_number);

            fflush(stdin);
            SetConsoleTextAttribute(h,2);
            gotoxy(30,33);
            cout<<"New Mobile No : ";
            SetConsoleTextAttribute(h,15);
            getline(cin,new_number);
            gotoxy(30,35);
            break;
        
        case 3:
            fflush(stdin);
            SetConsoleTextAttribute(h,2);
            gotoxy(30,31);
            cout<<"Old Profession : ";
            SetConsoleTextAttribute(h,15);
            getline(cin,old_profession);

            fflush(stdin);
            SetConsoleTextAttribute(h,2);
            gotoxy(30,33);
            cout<<"New Profession : ";
            SetConsoleTextAttribute(h,15);
            getline(cin,new_profession);
            gotoxy(30,35);
            break;
        
       
        default:

            SetConsoleTextAttribute(h,4);
            gotoxy(75,31);
            cout<<"Choose the correct number!!!";
            SetConsoleTextAttribute(h,15);
            gotoxy(30,33);
            updatecontact(oldname, newname, old_number, new_number, oldcity, newcity, old_address,new_address, old_profession, new_profession);
            break;
        }
        updatecontact(oldname, newname, old_number, new_number, oldcity, newcity, old_address,new_address, old_profession, new_profession);
        break;
    }
    default:

        SetConsoleTextAttribute(h,4);  
        gotoxy(75,18);
        cout<<"Choose the correct action!!! ";
        getch();
        SetConsoleTextAttribute(h,15);
        gotoxy(30,20);
        adminoptions();
        break;   
}
};
