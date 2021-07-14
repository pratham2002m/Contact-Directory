#include"contact_directory.h"
#include<iostream>
#include<conio.h>
using namespace std;
void load() //For Loading Screen
{
    int row,col,r,c,q;
    gotoxy(81,18);
    cout<<"Loading....";
    gotoxy(75,19);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++); //To Print The Character Slowly
        printf("%c",177);
    }
    cout<<"\n";
    gotoxy(56,21);
    cout<<"Loading Completed SuccessFully. Press Any Key To Continue";
    getch();
    system("cls");
}