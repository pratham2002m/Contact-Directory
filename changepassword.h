

#include<iostream>
#include<windows.h>
#include<fstream>
#include<string> 
#include<time.h>
#include<conio.h>

#include "class1.h"
// #include "load2.h"

using namespace std ;



void gotoxy8(short int x,short int y) // To Move The Cursor To The Desired Place
{
HANDLE Screen;
Screen = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Position={x, y};
SetConsoleCursorPosition(Screen, Position);
}


void load2() //For Load2ing Screen
{
    int row,col,r,c,q;
    gotoxy8(83,17);
    SetConsoleTextAttribute(h,3);
    printf("Load2ing...");
    gotoxy8(77,18);
    SetConsoleTextAttribute(h,9);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++); //To Print The Character Slowly
        printf("%c",177);
    }
    printf("\n");
    gotoxy8(57,20);
    SetConsoleTextAttribute(h,14);
    // printf("Load2ing Completed SuccessFully. Press Any Key To Continue");
    // getch();
    // system("cls");
}



void changepassword(){
    system("cls");
    SetConsoleTextAttribute(h,12); 
    gotoxy8(74,7);
    cout<<"Welcome To Contact Directory \n\n\n\n";

    gotoxy8(79,10);
    SetConsoleTextAttribute(h,11);
    cout<<"USER LOGIN PORTAL";


    string id,password,str,newpassword;
    int check = 0;
    SetConsoleTextAttribute(h,6);
    gotoxy8(30,13);
    cout<<"Enter your ID : ";
    SetConsoleTextAttribute(h,15);
    cin>>id;
    SetConsoleTextAttribute(h,6);
    gotoxy8(30,15);
    cout<<"Old Password : ";
    SetConsoleTextAttribute(h,15);
    cin>>password ;

    ifstream in("userdata.txt");
    ofstream out("temp.txt");
    getline(in,str);

    SetConsoleTextAttribute(h,6);
    gotoxy8(30,17);
    cout<<"New Password : ";
    SetConsoleTextAttribute(h,15);
    cin>>newpassword ;

    while (!in.eof())
    {
       if (str == "ID : " + id)
       {
           out<<str<<"\n";
           getline(in,str);
           if (str == "Password : " + password )
           {   
                check = 1 ;

                out<<"Password : "<<newpassword<<"\n";
                getline(in,str);

                load2();
                // SetConsoleTextAttribute(h,12); 
                // gotoxy8(74,7);
                // cout<<"Welcome To Contact Directory \n\n\n\n";

                // gotoxy8(79,10); 
                // SetConsoleTextAttribute(h,11);
                // cout<<"USER LOGIN PORTAL";
                // SetConsoleTextAttribute(h,13);
                // gotoxy8(30,12);
                // cout<<"Glad To See You , "<<id;
                // SetConsoleTextAttribute(h,14);
                // gotoxy8(30,14);
                // SetConsoleTextAttribute(h,15);
               
               



                gotoxy8(30,20);
                SetConsoleTextAttribute(h,14);
                cout<<"Your Password has been saved Successfully !!!";
                SetConsoleTextAttribute(h,15);
                getch();
             
                system("cls");

                exit(1);
                


           }
           
       }

       out<<str<<"\n";
       getline(in,str);
       
    }

    in.close();
    out.close();

    remove("userdata.txt");
    rename("temp.txt","userdata.txt");
    // system("cls");

    
}



