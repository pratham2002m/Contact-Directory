#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<time.h>
#include<conio.h>

#include "class1.h"

using namespace std ;


void gotoxy6(short int x,short int y) // To Move The Cursor To The Desired Place
{
HANDLE Screen;
Screen = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Position={x, y};
SetConsoleCursorPosition(Screen, Position);
}


void load3() //For Loading Screen
{
    int row,col,r,c,q;
    gotoxy3(83,17);
    SetConsoleTextAttribute(h,3);
    printf("Loading...");
    gotoxy3(77,18);
    SetConsoleTextAttribute(h,9);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++); //To Print The Character Slowly
        printf("%c",177);
    }
    printf("\n");
    gotoxy3(57,20);
    SetConsoleTextAttribute(h,14);
    printf("Loading Completed SuccessFully. Press Any Key To Continue");
    getch();
    // system("cls");
}



void newaccount(){

    string id,password ;

    SetConsoleTextAttribute(h,8);
    gotoxy6(30,16);
    cout<<"Create your ID : ";
    SetConsoleTextAttribute(h,15);
    cin>>id ;
    SetConsoleTextAttribute(h,8);
    gotoxy6(30,18);
    cout<<"Password : ";
    SetConsoleTextAttribute(h,15);
    cin>>password ;

    ofstream out("userdata.txt",ios::app);
    out<<"\nID : "<<id<<"\n";
    out<<"Password : "<<password<<"\n" ;
    out<<"Last login : "<<__DATE__<<" "<<__TIME__<<"\n";

    out.close();

    load3();
    SetConsoleTextAttribute(h,13);
    gotoxy6(64,25);
    cout<<"Your Account Has Been Created Successfully\n\n";
    SetConsoleTextAttribute(h,10);
    gotoxy6(64,30);
    cout<<"********  Thank You From Contact-Directory  ********\n\n\n\n\n\n";
    exit(1);

}