#include<iostream>
#include<windows.h>
#include<fstream>
#include<string> 
#include<time.h>
#include<conio.h>

#include "class1.h"
// #include "load1.h"

using namespace std ;



void gotoxy5(short int x,short int y) // To Move The Cursor To The Desired Place
{
HANDLE Screen;
Screen = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Position={x, y};
SetConsoleCursorPosition(Screen, Position);
}


void load1() //For Load1ing Screen
{
    int row,col,r,c,q;
    gotoxy5(83,17);
    SetConsoleTextAttribute(h,3);
    printf("Load1ing...");
    gotoxy5(77,18);
    SetConsoleTextAttribute(h,9);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++); //To Print The Character Slowly
        printf("%c",177);
    }
    printf("\n");
    gotoxy5(57,20);
    SetConsoleTextAttribute(h,14);
    printf("Load1ing Completed SuccessFully. Press Any Key To Continue");
    getch();
    system("cls");
}



int login(){
    system("cls");
    SetConsoleTextAttribute(h,12); 
    gotoxy5(74,7);
    cout<<"Welcome To Contact Directory \n\n\n\n";

    gotoxy5(79,10);
    SetConsoleTextAttribute(h,11);
    cout<<"USER LOGIN PORTAL";
    string id,password,str;
    // char change_password ;
    int check = 0;
    SetConsoleTextAttribute(h,6);
    gotoxy5(30,13);
    cout<<"Enter your ID : ";
    SetConsoleTextAttribute(h,15);
    cin>>id;
    SetConsoleTextAttribute(h,6);
    gotoxy5(30,15);
    cout<<"Password : ";
    SetConsoleTextAttribute(h,0);
    cin>>password ;
    SetConsoleTextAttribute(h,15);
    ifstream in("userdata.txt");
    ofstream out("temp.txt");
    getline(in,str);

    while (!in.eof())
    {
       if (str == "ID : " + id)
       {
           out<<str<<"\n";
           getline(in,str);
           if (str == "Password : " + password )
           {   
                load1();
                SetConsoleTextAttribute(h,12); 
                gotoxy5(74,7);
                cout<<"Welcome To Contact Directory \n\n\n\n";

                gotoxy5(79,10);
                SetConsoleTextAttribute(h,11);
                cout<<"USER LOGIN PORTAL";
                SetConsoleTextAttribute(h,13);
                gotoxy5(30,12);
                cout<<"Glad To See You , "<<id;
                // SetConsoleTextAttribute(h,14);
                // gotoxy5(30,14);
                // cout<<"Would You Like To Change Your Password ? y/n    ";
                SetConsoleTextAttribute(h,15);
                // cin>>change_password;

               check = 1;
            //    if (change_password == 'y')
            //    {
            //        string newpassword;
            //        SetConsoleTextAttribute(h,6);
            //        gotoxy5(30,16);
            //        cout<<"Please Enter Your New Password : ";
            //        SetConsoleTextAttribute(h,15);
            //        cin>>newpassword ;
            //        out<<"Password : "<<newpassword<<"";
                 
            //    }
            //    else
            //    {
                //    out<<str<<"\n";
                //    SetConsoleTextAttribute(h,6);
                //    gotoxy5(30,16);
                //    cout<<"You can change your PassWord Anytime By Logging in Again";
            //    }
               
                gotoxy5(30,16);
                out<<str<<"";
                out<<"\nLast login : "<<__DATE__<<" "<<__TIME__<<"\n";
                getline(in,str);
                getline(in,str);
           }
           
       }

       out<<str<<"\n";
       getline(in,str);
       
    }

    in.close();
    out.close();

    remove("userdata.txt");
    rename("temp.txt","userdata.txt");

    gotoxy5(30,10);
    cout<<check<<endl;

    
    if (check == 1)
    {
        return 1;
    }
    else
    {
        gotoxy5(30,25);
        SetConsoleTextAttribute(h,11);
        cout<<"Please check your username and password again !!!"<<endl;
        SetConsoleTextAttribute(h,15);
        getch();
        return 0 ;
    }
    
    
}



