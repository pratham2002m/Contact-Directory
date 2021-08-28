// Libraries Used :
#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<time.h>
#include<conio.h>


#include "load.h"
#include "adminoptions.h"
#include "userlogin.h"

using namespace std;


void admin();
void user();
 
void start();

void changepassword();

// Classes 
class data1 ;




int main(){

   start();

   SetConsoleTextAttribute(h,6);
   
   char repeat ;
   cout<<"TRY AGAIN ? y/n : ";
   cin>>repeat;
   cout<<"\n\n";
   if (repeat == 'y')
   {
     SetConsoleTextAttribute(h,15);
     main();
   }
 return 0;
}


// This is a function to start the program
void start(){
    start:
    system("cls");
    SetConsoleTextAttribute(h,12); 
    gotoxy(74,7);
    cout<<"Welcome To Contact Directory \n\n\n\n";

    gotoxy(30,11);
    SetConsoleTextAttribute(h,6);
    cout<<"1. Admin\n";
    gotoxy(30,12);
    cout<<"2. User\n\n";
    SetConsoleTextAttribute(h,15); 
   

    int role ;
    SetConsoleTextAttribute(h,2); 
    gotoxy(30,15);
    cout<<"Enter your role : ";
    SetConsoleTextAttribute(h,15);
    cin>>role;
    
    if (role == 1)
    {
        admin();
    }
    else if(role == 2)
    {
        user();
    }
    else
    {
        gotoxy(30,20);
        cout<<"Please Enter The Correct Option !!! "<<endl;
        getch();
        start();
    }

}

// Function for handling admin requests
void admin(){

    system("cls");
    SetConsoleTextAttribute(h,12); 
    gotoxy(74,7);
    cout<<"Welcome To Contact Directory \n\n\n\n";

    gotoxy(79,10);
    SetConsoleTextAttribute(h,11);
    cout<<"ADMIN LOGIN PORTAL";
    static int chances = 3 ;
    string password;

    SetConsoleTextAttribute(h,4);
    gotoxy(30,14);
    cout<<"Enter the password : ";
    SetConsoleTextAttribute(h,15);
    cin>>password ;
    if (password == "1234")
    {   
        load();
        adminoptions();
    }
    else
    {
        chances--;
        if (chances != 0)
        {
            SetConsoleTextAttribute(h,11);
            gotoxy(30,17);
            cout<<"Only "<<chances<<" chances left !!!";
            getch();
            SetConsoleTextAttribute(h,4);
            admin();
        }
        else
        {
            SetConsoleTextAttribute(h,10);
            gotoxy(79,18);
            cout<<"Try again later!!!";
            Sleep(2000);
            exit(1);
            
        }      
    }
};

void user(){

    system("cls");
    SetConsoleTextAttribute(h,12); 
    gotoxy(74,7);
    cout<<"Welcome To Contact Directory \n\n\n\n";

    gotoxy(79,10);
    SetConsoleTextAttribute(h,11);
    cout<<"USER LOGIN PORTAL";
    userlogin();



    string city,name,profession,number;

    

    fflush(stdin);
    SetConsoleTextAttribute(h,2);
    gotoxy(30,18);
    cout<<"Enter the City : ";
    SetConsoleTextAttribute(h,15);
    getline(cin,city);

    ifstream in;
    string file = city.append(".txt");
    in.open(file);

    if (!in)
    {
        SetConsoleTextAttribute(h,8);
        gotoxy(30,20);
        cout<<"No such city found !!!"<<endl;
        SetConsoleTextAttribute(h,15);
        gotoxy(30,22);
        return ;
    }
    
 
    SetConsoleTextAttribute(h,4);
    gotoxy(30,20);
    cout<<"Enter info you know : "<<endl;

    int choice,flag=0 ;
    string str;
    string sname,snumber,sprofession; // To search by mobile and profession

    SetConsoleTextAttribute(h,9);
    gotoxy(30,21);
    cout<<"1.Name only";
    gotoxy(30,22);
    cout<<"2.Mobile No. only";
    gotoxy(30,23);
    cout<<"3.Profession only";
    gotoxy(30,24);
    cout<<"4.Name & Profession";
    gotoxy(30,25);
    cout<<"5.Name & Mobile No";
    gotoxy(30,26);
    cout<<"6.Profession & Mobile No";
    gotoxy(30,27);
    cout<<"7.Name,Mobile No,Profession    ";
    SetConsoleTextAttribute(h,15);

    cin>>choice;
    
    switch (choice)
    {
    case 1:    // Name Only

        system("cls");
        SetConsoleTextAttribute(h,12); 
        gotoxy(74,7);
        cout<<"Welcome To Contact Directory \n\n\n\n";

        gotoxy(79,10);
        SetConsoleTextAttribute(h,11);
        cout<<"USER LOGIN PORTAL";
        fflush(stdin);
        SetConsoleTextAttribute(h,2);
        gotoxy(30,12);
        cout<<"Enter the name : ";
        SetConsoleTextAttribute(h,15);
        getline(cin,name);

        getline(in,str);
        while (!in.eof())
        {
            if (str == "Name : " + name)
            {
                flag = 1 ;
                gotoxy(30,14);
                cout<<str<<"\n";
                getline(in,str);
                gotoxy(30,16);
                cout<<str<<"\n";
                getline(in,str);
                gotoxy(30,18);
                cout<<str<<"\n";
                getline(in,str);
                gotoxy(30,20);
                cout<<str<<"\n";
                getline(in,str);
                gotoxy(30,22);
                cout<<str<<"\n";
                gotoxy(30,24);
            }
            
            getline(in,str);
        }
        if (flag == 0)
        {
            SetConsoleTextAttribute(h,14);  
            gotoxy(30,14);
            cout<<"Data is not found !!!"<<endl;
            gotoxy(30,16);
        }
        
        break;
 
    case 2:   // Mobile No. only

        system("cls");
        SetConsoleTextAttribute(h,12); 
        gotoxy(74,7);
        cout<<"Welcome To Contact Directory \n\n\n\n";

        gotoxy(79,10);
        SetConsoleTextAttribute(h,11);
        cout<<"USER LOGIN PORTAL";
        SetConsoleTextAttribute(h,2);  
        gotoxy(30,12);
        cout<<"Enter Mobile No : ";
        SetConsoleTextAttribute(h,15);  
        cin>>number ;

        fflush(stdin);
        getline(in,str);
        

        while (!in.eof())
        {
            if (str.substr(0,4) == "Name"){
                sname = str ;
            }
    
            if (str == "Mobile no : " + number)
            {
                flag = 1 ;
                gotoxy(30,14);
                cout<<sname;
                gotoxy(30,16);
                cout<<str<<"\n";
                getline(in,str);
                gotoxy(30,18);
                cout<<str<<"\n";
                getline(in,str);
                gotoxy(30,20);
                cout<<str<<"\n";
                getline(in,str);
                gotoxy(30,22);
                cout<<str<<"\n";
                gotoxy(30,24);
                
            }
                
               
             getline(in,str);
        }
            
            
        if (flag == 0)
        {
            SetConsoleTextAttribute(h,4);  
            gotoxy(30,14);
            cout<<"Data is not found !!!"<<endl;
            gotoxy(30,16);
        }
        
        break;
    case 3:              // Profession only
        system("cls");
        SetConsoleTextAttribute(h,12); 
        gotoxy(74,7);
        cout<<"Welcome To Contact Directory \n\n\n\n";

        gotoxy(79,10);
        SetConsoleTextAttribute(h,11);
        cout<<"USER LOGIN PORTAL";
        getline(in,str);

        SetConsoleTextAttribute(h,2); 
        gotoxy(30,12); 
        cout<<"Enter the profession : ";
        SetConsoleTextAttribute(h,15);  
        fflush(stdin);
        getline(cin,profession);
        
        while (!in.eof())
        {
            
            if (str.substr(0,4) == "Name")
            {
                sname = str ;
            }

            if (str.substr(0,6) == "Mobile")
            {
                snumber = str ;
            }
            
            
            if (str == ("Profession : " + profession))
            {
                
                flag = 1 ;
                gotoxy(30,14);
                cout<<sname<<endl;
                gotoxy(30,16); 
                cout<<snumber<<endl;
                gotoxy(30,18); 
                cout<<str<<"\n";
                getline(in,str);
                gotoxy(30,20); 
                cout<<str<<"\n";
                getline(in,str);
                gotoxy(30,22); 
                cout<<str<<"\n";
                gotoxy(30,24); 
                
            }
            
            getline(in,str);
        }
        if (flag == 0)
        {
            SetConsoleTextAttribute(h,4);  
            gotoxy(30,14); 
            cout<<"Data is not found !!!"<<endl;
            gotoxy(30,16); 
        }
        
        break;
    
    case 4:      // Name & Profession

        system("cls");
        SetConsoleTextAttribute(h,12); 
        gotoxy(74,7);
        cout<<"Welcome To Contact Directory \n\n\n\n";

        gotoxy(79,10);
        SetConsoleTextAttribute(h,11);
        cout<<"USER LOGIN PORTAL";
        SetConsoleTextAttribute(h,2);  
        gotoxy(30,12); 
        cout<<"Enter the Name : ";
        SetConsoleTextAttribute(h,15);  
        fflush(stdin);
        getline(cin,name);

        SetConsoleTextAttribute(h,2);  
        gotoxy(30,14); 
        cout<<"Enter the Profession : ";
        SetConsoleTextAttribute(h,15);  
        fflush(stdin);
        getline(cin,profession);

        getline(in,str);
        
        while (!in.eof())
        {

            if (str == "Name : " + name)
            {
                sname = str ;
                getline(in,str);
                snumber = str ;
                getline(in,str);
                if (str == "Profession : " + profession)
                {
                        flag = 1;
                        gotoxy(30,16); 
                        cout<<sname<<endl;
                        gotoxy(30,18); 
                        cout<<snumber<<endl; 
                        gotoxy(30,20); 
                        cout<<str<<"\n";
                        getline(in,str);
                        gotoxy(30,22); 
                        cout<<str<<"\n";
                        getline(in,str);
                        gotoxy(30,24); 
                        cout<<str<<"\n";
                        gotoxy(30,26); 
                }
                
            }
            
            getline(in,str);
        }
        if (flag == 0)
        {
            SetConsoleTextAttribute(h,4);  
            gotoxy(30,16); 
            cout<<"Data is not found !!!"<<endl;
            gotoxy(30,18); 
        }
        
        break;

    case 5:       //  Name & Mobile No

        system("cls");
        SetConsoleTextAttribute(h,12); 
        gotoxy(74,7);
        cout<<"Welcome To Contact Directory \n\n\n\n";

        gotoxy(79,10);
        SetConsoleTextAttribute(h,11);
        cout<<"USER LOGIN PORTAL";
        SetConsoleTextAttribute(h,2);  
        gotoxy(30,12);
        cout<<"Enter the Name : ";
        SetConsoleTextAttribute(h,15);  
        fflush(stdin);
        getline(cin,name);

        SetConsoleTextAttribute(h,2);  
        gotoxy(30,14); 
        cout<<"Enter the Mobile No : ";
        SetConsoleTextAttribute(h,15);  
        fflush(stdin);
        getline(cin,number);

        getline(in,str);
        
        while (!in.eof())
        {

            if (str == "Name : " + name)
            {
                // cout<<"Check1"<<endl;
                sname = str ;
                getline(in,str);
                fflush(stdin);
                if (str == "Mobile no : " + number)
                {
                        // cout<<"Check2"<<endl;
                        flag = 1 ;
                        gotoxy(30,16); 
                        cout<<sname<<endl;
                        gotoxy(30,18); 
                        cout<<str<<"\n";
                        getline(in,str);
                        gotoxy(30,20); 
                        cout<<str<<"\n";
                        getline(in,str);
                        gotoxy(30,22); 
                        cout<<str<<"\n";
                        getline(in,str);
                        gotoxy(30,24); 
                        cout<<str<<"\n";
                        gotoxy(30,26); 
                }
                
            }
            
            getline(in,str);
        }
        if (flag == 0)
        {
            SetConsoleTextAttribute(h,4);  
            gotoxy(30,16); 
            cout<<"Data is not found !!!"<<endl;
            gotoxy(30,18); 
        }
        
        break;
    
    case 6:                // Profession & Mobile No

        system("cls");
        SetConsoleTextAttribute(h,12); 
        gotoxy(74,7);
        cout<<"Welcome To Contact Directory \n\n\n\n";

        gotoxy(79,10);
        SetConsoleTextAttribute(h,11);
        cout<<"USER LOGIN PORTAL";
        SetConsoleTextAttribute(h,2);  
        gotoxy(30,12); 
        cout<<"Enter the Mobile No : ";
        SetConsoleTextAttribute(h,15);  
        fflush(stdin);
        getline(cin,number);

        SetConsoleTextAttribute(h,2);  
        gotoxy(30,14); 
        cout<<"Enter the Profession : ";
        SetConsoleTextAttribute(h,15);  
        fflush(stdin);
        getline(cin,profession);
        

        getline(in,str);
        
        while (!in.eof())
        {

            if (str == "Mobile no : " + number)
            {
                snumber = str ;

                getline(in,str);

                if (str == "Profession : " + profession)
                {
                        flag = 1;
                        gotoxy(30,16); 
                        cout<<sname<<endl;
                        gotoxy(30,18); 
                        cout<<snumber<<endl;
                        gotoxy(30,20); 
                        cout<<str<<"\n";
                        getline(in,str);
                        gotoxy(30,22); 
                        cout<<str<<"\n";
                        getline(in,str);
                        gotoxy(30,24); 
                        cout<<str<<"\n";
                        gotoxy(30,26); 
                }
                
            }

            sname = str ;
            
            getline(in,str);
        }
        if (flag == 0)
        {   
            SetConsoleTextAttribute(h,4); 
            gotoxy(30,16); 
            cout<<"Data is not found !!!"<<endl;
            gotoxy(30,18); 
        }
        
        break;
    case 7:      // All 

        system("cls");
        SetConsoleTextAttribute(h,12); 
        gotoxy(74,7);
        cout<<"Welcome To Contact Directory \n\n\n\n";

        gotoxy(79,10);
        SetConsoleTextAttribute(h,11);
        cout<<"USER LOGIN PORTAL";
        getline(in,str);
        gotoxy(30,12);
        SetConsoleTextAttribute(h,2);  
        
        cout<<"Enter the name : ";
        SetConsoleTextAttribute(h,15);  
        fflush(stdin);
        getline(cin,name);

        SetConsoleTextAttribute(h,2);  
        gotoxy(30,14); 
        cout<<"Enter the Mobile No : ";
        SetConsoleTextAttribute(h,15);  
        fflush(stdin);
        getline(cin,number);

        SetConsoleTextAttribute(h,2);  
        gotoxy(30,16); 
        cout<<"Enter the Profession : ";
        SetConsoleTextAttribute(h,15);  
        fflush(stdin);
        getline(cin,profession);

        while (!in.eof())
        {
            if (str == "Name : " + name)
            {
                sname = str ;
                getline(in,str);

                if (str == "Mobile no : " + number)
                {
                    snumber = str ;
                    getline(in,str);

                    if (str == "Profession : " + profession)
                    {
                        flag = 1;
                        gotoxy(30,18); 
                        cout<<sname<<endl;
                        gotoxy(30,20); 
                        cout<<snumber<<endl;
                        gotoxy(30,22); 
                        cout<<str<<"\n";
                        getline(in,str);
                        gotoxy(30,24); 
                        cout<<str<<"\n";
                        getline(in,str);
                        gotoxy(30,26); 
                        cout<<str<<"\n";
                        gotoxy(30,28); 
                    }
                    
                }
                
            }
            
            getline(in,str);
        }
        if (flag == 0)
        {
            SetConsoleTextAttribute(h,4);  
            gotoxy(30,18); 
            cout<<"Data is not found !!!"<<endl;
            gotoxy(30,20); 
        }
        
        break;
    
    default:
        SetConsoleTextAttribute(h,4);  
        gotoxy(30,29);
        cout<<"Please Enter the correct option !!! ";
        getch();
        SetConsoleTextAttribute(h,15);  
        user();
        break;
    }
    
    

    
}