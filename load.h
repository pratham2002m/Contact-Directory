#include<iostream>
#include<windows.h>
#include<conio.h>

// #include "gotoxy3.h"
#include "class1.h" 

using namespace std;



void gotoxy3(short int x,short int y) // To Move The Cursor To The Desired Place
{
HANDLE Screen;
Screen = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Position={x, y};
SetConsoleCursorPosition(Screen, Position);
}



void load() //For Loading Screen
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
    system("cls");
}
