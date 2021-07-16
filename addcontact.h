#pragma once
#include<iostream>
#include<string> 
#include<windows.h>
 

#include "class1.h"
// #include "gotoxy2.h"


void gotoxy2(short int x,short int y) // To Move The Cursor To The Desired Place
{
HANDLE Screen;
Screen = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Position={x, y};
SetConsoleCursorPosition(Screen, Position);
}



using namespace std ;


void addcontact(){

    fflush(stdin);
    string name ;
    SetConsoleTextAttribute(h,12);
    gotoxy2(80,18);
    cout<<"ADD CONTACT FORM";
    SetConsoleTextAttribute(h,14);
    gotoxy2(30,21);
    cout<<"Full Name : ";
    SetConsoleTextAttribute(h,15);
    getline(cin,name);

    fflush(stdin) ;
    string number;
    SetConsoleTextAttribute(h,14);
    gotoxy2(30,23);
    cout<<"Mobile Number : ";
    SetConsoleTextAttribute(h,15);
    cin>>number;

    fflush(stdin) ;
    string city;
    SetConsoleTextAttribute(h,14);
    gotoxy2(30,25);
    cout<<"City : ";
    SetConsoleTextAttribute(h,15);
    cin>>city;

    fflush(stdin);
    string address;
    SetConsoleTextAttribute(h,14);
    gotoxy2(30,27);
    cout<<"Address : ";
    SetConsoleTextAttribute(h,15);
    getline(cin,address);
    
    fflush(stdin);
    string profession;
    SetConsoleTextAttribute(h,14);
    gotoxy2(30,29);
    cout<<"Profession : ";
    SetConsoleTextAttribute(h,15);
    getline(cin,profession) ;
    fflush(stdin);


    data1 cntdata(name,number,address,city,profession);
    // data cntdata(name,number,address,city,profession);
    cntdata.storedata();

    Sleep(1000);

    SetConsoleTextAttribute(h,11);
    gotoxy2(71,31);
    cout<<"Data has been saved successfully !!!";
    SetConsoleTextAttribute(h,15);
    gotoxy2(30,33);

}
