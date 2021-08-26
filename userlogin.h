#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<time.h>
#include<conio.h>

// #include "class1.h"
#include "newaccount.h"
#include "login.h" 
#include "changepassword.h"


void gotoxy7(short int x,short int y) // To Move The Cursor To The Desired Place
{
HANDLE Screen;
Screen = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Position={x, y};
SetConsoleCursorPosition(Screen, Position);
}


void userlogin(){

    system("cls");
    SetConsoleTextAttribute(h,12); 
    gotoxy5(74,7);
    cout<<"Welcome To Contact Directory \n\n\n\n";

    gotoxy5(79,10);
    SetConsoleTextAttribute(h,11);
    cout<<"USER LOGIN PORTAL";

    int choice;
    SetConsoleTextAttribute(h,6);
    gotoxy7(30,12);
    cout<<"1.Login";
    gotoxy7(30,14);
    cout<<"2.Create Account     ";
    gotoxy7(30,16);
    cout<<"3.Change Password     ";
    SetConsoleTextAttribute(h,15);
    cin>>choice;

    switch (choice)
    {
        case 1:
        {
                    int c = 3 ;
                    while (c != 0)
                    {
                            int a = login();
                            if (a == 0)
                            {
                                c -- ;
                                SetConsoleTextAttribute(h,3);
                                gotoxy7(30,19);
                                cout<<"Enter the correct data !!!";
                                gotoxy7(30,21);
                                cout<<"Only "<<c<<" chances left !!! ";
                                SetConsoleTextAttribute(h,15);
                                getch();
                            }
                            else
                            {
                                return ;
                            }
                            
                    }
                        SetConsoleTextAttribute(h,14);
                        gotoxy7(30,21);
                        cout<<"Try Again Later!!!"<<endl;
                        exit(1);
                    
                    break;
        }
        case 2:
            newaccount();
            break;
        case 3:
            changepassword();
            userlogin();
            break;
        
        default:
            gotoxy7(30,18);
            SetConsoleTextAttribute(h,14);
            cout<<"Please enter the correct option !!!"<<endl;
            getch();
            SetConsoleTextAttribute(h,15);
            userlogin();
            break;
        }

}

