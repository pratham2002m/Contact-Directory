// Libraries Used :
#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<time.h>
#include<conio.h>

// #include "addcontact.h"
#include "load.h"
#include "adminoptions.h"
#include "userlogin.h"
// #include "newaccount.h"

using namespace std;

//  Functions 
// void adminoptions();

// void addcontact();

// void removecontact(string,string,string);

// void updatecontact(string,string,string,string,string,string,string,string,string,string);

void admin();
void user();
 
void start();

// void storedata();

// void userlogin();

// int login();

void changepassword();

// void newaccount();

// void gotoxy(short , short);

// void load();

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

// Function to provide options to admin for action
// void adminoptions(){
    
//     system("cls");
//     SetConsoleTextAttribute(h,12); 
//     gotoxy(74,7);
//     cout<<"Welcome To Contact Directory \n\n\n\n";
//     SetConsoleTextAttribute(h,2);
//     gotoxy(30,10);
//     cout<<"Choose your action : ";

//     int action ;

//     SetConsoleTextAttribute(h,14);
//     gotoxy(30,12);
//     cout<<"1. Add a contact"<<endl;
//     SetConsoleTextAttribute(h,3);
//     gotoxy(30,13);
//     cout<<"2. Remove a contact"<<endl;
//     SetConsoleTextAttribute(h,4);
//     gotoxy(30,14);
//     cout<<"3. Update a contact ";
//     SetConsoleTextAttribute(h,7);
//     gotoxy(30,16);
//     cin>>action;

//     SetConsoleTextAttribute(h,15);

//     switch (action)
//     {

//     case 1:
//         addcontact();
//         break;
    
//     case 2:
//     {
//         fflush(stdin);
//         SetConsoleTextAttribute(h,12);
//         gotoxy(78,18);
//         cout<<"REMOVE CONTACT FORM";
//         string name,city,number;

//         SetConsoleTextAttribute(h,14);
//         gotoxy(30,21);
//         cout<<"Name of user : ";
//         SetConsoleTextAttribute(h,15);
//         getline(cin,name);

//         fflush(stdin);
//         SetConsoleTextAttribute(h,14);
//         gotoxy(30,23);
//         cout<<"City : ";
//         SetConsoleTextAttribute(h,15);
//         getline(cin,city);

//         fflush(stdin);
//         SetConsoleTextAttribute(h,14);
//         gotoxy(30,25);
//         cout<<"Mobile no : ";
//         SetConsoleTextAttribute(h,15);
//         cin>>number ;

//         fflush(stdin);
//         removecontact(name,city,number);

//         break;
//     }
//     case 3:
//     {
//         int action ;

//         SetConsoleTextAttribute(h,12);
//         gotoxy(78,18);
//         cout<<"UPDATE CONTACT FORM";

//         gotoxy(30,21);
//         SetConsoleTextAttribute(h,10);
//         cout<<"Choose the format : "<<endl;
//         SetConsoleTextAttribute(h,14);
//         gotoxy(30,23);
//         cout<<"1.Name";
//         gotoxy(30,25);
//         cout<<"2.Mobile No.";
//         gotoxy(30,27);
//         cout<<"3.Profession ";
//         gotoxy(49,27);
//         SetConsoleTextAttribute(h,15);
//         cin>>action;

//         SetConsoleTextAttribute(h,15);
   

//         string oldname, newname, old_number, new_number, oldcity, newcity, old_address,new_address, old_profession, new_profession ;

//         fflush(stdin);

//         SetConsoleTextAttribute(h,11);
//         gotoxy(30,29);
//         cout<<"City : ";
//         SetConsoleTextAttribute(h,15);
//         getline(cin,oldcity);

//         switch (action)
//         {

//         case 1:
//             fflush(stdin);
//             SetConsoleTextAttribute(h,2);
//             gotoxy(30,31);
//             cout<<"Old Name : ";
//             SetConsoleTextAttribute(h,15);
//             getline(cin,oldname);

//             fflush(stdin);
//             SetConsoleTextAttribute(h,2);
//             gotoxy(30,33);
//             cout<<"New Name : ";
//             SetConsoleTextAttribute(h,15);
//             getline(cin,newname);
//             gotoxy(30,35);
//             break;
        
       
//         case 2:
//             fflush(stdin);
//             SetConsoleTextAttribute(h,2);
//             gotoxy(30,31);
//             cout<<"Old Mobile No : ";
//             SetConsoleTextAttribute(h,15);
//             getline(cin,old_number);

//             fflush(stdin);
//             SetConsoleTextAttribute(h,2);
//             gotoxy(30,33);
//             cout<<"New Mobile No : ";
//             SetConsoleTextAttribute(h,15);
//             getline(cin,new_number);
//             gotoxy(30,35);
//             break;
        
//         case 3:
//             fflush(stdin);
//             SetConsoleTextAttribute(h,2);
//             gotoxy(30,31);
//             cout<<"Old Profession : ";
//             SetConsoleTextAttribute(h,15);
//             getline(cin,old_profession);

//             fflush(stdin);
//             SetConsoleTextAttribute(h,2);
//             gotoxy(30,33);
//             cout<<"New Profession : ";
//             SetConsoleTextAttribute(h,15);
//             getline(cin,new_profession);
//             gotoxy(30,35);
//             break;
        
       
//         default:

//             SetConsoleTextAttribute(h,4);
//             gotoxy(75,31);
//             cout<<"Choose the correct number!!!";
//             SetConsoleTextAttribute(h,15);
//             gotoxy(30,33);
//             updatecontact(oldname, newname, old_number, new_number, oldcity, newcity, old_address,new_address, old_profession, new_profession);
//             break;
//         }
//         updatecontact(oldname, newname, old_number, new_number, oldcity, newcity, old_address,new_address, old_profession, new_profession);
//         break;
//     }
//     default:

//         SetConsoleTextAttribute(h,4);  
//         gotoxy(75,18);
//         cout<<"Choose the correct action!!! ";
//         getch();
//         SetConsoleTextAttribute(h,15);
//         gotoxy(30,20);
//         adminoptions();
//         break;   
// }
// };

// Function to add data to contacts
// void addcontact(){

//     fflush(stdin);
//     string name ;
//     SetConsoleTextAttribute(h,12);
//     gotoxy(80,18);
//     cout<<"ADD CONTACT FORM";
//     SetConsoleTextAttribute(h,14);
//     gotoxy(30,21);
//     cout<<"Full Name : ";
//     SetConsoleTextAttribute(h,15);
//     getline(cin,name);

//     fflush(stdin) ;
//     string number;
//     SetConsoleTextAttribute(h,14);
//     gotoxy(30,23);
//     cout<<"Mobile Number : ";
//     SetConsoleTextAttribute(h,15);
//     cin>>number;

//     fflush(stdin) ;
//     string city;
//     SetConsoleTextAttribute(h,14);
//     gotoxy(30,25);
//     cout<<"City : ";
//     SetConsoleTextAttribute(h,15);
//     cin>>city;

//     fflush(stdin);
//     string address;
//     SetConsoleTextAttribute(h,14);
//     gotoxy(30,27);
//     cout<<"Address : ";
//     SetConsoleTextAttribute(h,15);
//     getline(cin,address);
    
//     fflush(stdin);
//     string profession;
//     SetConsoleTextAttribute(h,14);
//     gotoxy(30,29);
//     cout<<"Profession : ";
//     SetConsoleTextAttribute(h,15);
//     getline(cin,profession) ;
//     fflush(stdin);


//     data1 cntdata(name,number,address,city,profession);
//     // data cntdata(name,number,address,city,profession);
//     cntdata.storedata();

//     Sleep(1000);

//     SetConsoleTextAttribute(h,11);
//     gotoxy(71,31);
//     cout<<"Data has been saved successfully !!!";
//     SetConsoleTextAttribute(h,15);
//     gotoxy(30,33);

// }

// void removecontact(string name,string city,string number){

//     string str;
//     ifstream in ;

//     string tempfile = "temp.txt";
//     ofstream out(tempfile) ;
//     string file = city.append(".txt") ;
//     in.open(file);
//     getline(in,str);
//     while (!in.eof())
//     {
//         if (str == "Name : " + name)
//         {
//              getline(in,str);
//              if (str == "Mobile no : " + number)
//              {
//                  SetConsoleTextAttribute(h,11);
//                  gotoxy(71,28);
//                  cout<<"Data has been removed successfully !!!\n\n\n"<<endl;

//                   // To delete address city profession
//                 getline(in,str); 
//                 getline(in,str);
//                 getline(in,str);
//                 getline(in,str);
//                 getline(in,str);
//                 gotoxy(30,30);
//              }
//              else       // If mobile number is not same
//              {
//                  out<<str<<"\n";

//                  getline(in,str);
//                  out<<str<<"\n";

//                  getline(in,str);
//                  out<<str<<"\n";

//                  getline(in,str);
//                  out<<str<<"\n";

//                  getline(in,str);
//                  out<<str<<"\n";

                 
                
//              }
             
//         }
       
//          out<<str<<"\n";
//          getline(in,str); 
//          gotoxy(30,30);
//     }

//     in.close();
//     out.close();

//     remove(file.c_str());
//     rename("temp.txt",file.c_str());


// }

// void updatecontact(string oldname,string newname,string old_number,string new_number,string oldcity,string newcity,string old_address,string new_address,string old_profession,string new_profession){

//     string str;
//     ifstream in ;

//     string tempfile = "temp.txt";
//     ofstream out(tempfile) ;

    
   

//     string file = oldcity.append(".txt") ;
//     in.open(file);

//     getline(in,str);

//     while (!in.eof())
//     {
//         if (str == "Name : " + oldname)
//         {
//             out<<"Name : " + newname<<"\n" ;    
//             getline(in,str);
//         }

//         if (str == "Mobile no : " + old_number)
//         {
//             out<<"Mobile no : " + new_number<<"\n" ; 
//             getline(in,str);   
//         }

//         if (str == "Address : " + old_address)
//         {
//             out<<"Address : " + new_address<<"\n" ;    
//             getline(in,str);
//         }

//         if (str == "Profession : " + old_profession)
//         {
//             out<<"Profession : " + new_profession<<"\n" ;    
//             getline(in,str);
//         }

       
//         out<<str<<"\n";
//         getline(in,str);
        
//     }

//     in.close();
//     out.close();

//     remove(file.c_str());
//     rename("temp.txt",file.c_str());
// }

// User login,change password,signup features

// void newaccount(){

//     string id,password ;

//     SetConsoleTextAttribute(h,8);
//     gotoxy(30,16);
//     cout<<"Create your ID : ";
//     SetConsoleTextAttribute(h,15);
//     cin>>id ;
//     SetConsoleTextAttribute(h,8);
//     gotoxy(30,18);
//     cout<<"Password : ";
//     SetConsoleTextAttribute(h,15);
//     cin>>password ;

//     ofstream out("userdata.txt",ios::app);
//     out<<"\nID : "<<id<<"\n";
//     out<<"Password : "<<password<<"\n" ;
//     out<<"Last login : "<<__DATE__<<" "<<__TIME__<<"\n";

//     out.close();

//     SetConsoleTextAttribute(h,2);
//     gotoxy(64,20);
//     cout<<"********  Welcome To Contact - Directory  ********";
//     exit(1);

// }

// void userlogin(){

//     int choice;
//     SetConsoleTextAttribute(h,6);
//     gotoxy(30,12);
//     cout<<"1.Login";
//     gotoxy(30,14);
//     cout<<"2.Create Account     ";
//     SetConsoleTextAttribute(h,15);
//     cin>>choice;

//     switch (choice)
//     {
//     case 1:
//     {
//                 int c = 3 ;
//                 while (c != 0)
//                 {
//                         int a = login();
//                         if (a == 0)
//                         {
//                             c -- ;
//                             SetConsoleTextAttribute(h,3);
//                             gotoxy(30,17);
//                             cout<<"Enter the correct data !!!";
//                             gotoxy(30,19);
//                             cout<<"Only "<<c<<" chances left !!! ";
//                             SetConsoleTextAttribute(h,15);
//                             getch();
//                         }
//                         else
//                         {
//                             return ;
//                         }
                        
//                 }
//                     SetConsoleTextAttribute(h,14);
//                     gotoxy(30,21);
//                     cout<<"Try Again Later!!!"<<endl;
//                     exit(1);
                
//                 break;
//     }
//     case 2:
//         newaccount();
//         break;
    
//     default:
//         break;
//     }

// }



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
// void load() //For Loading Screen
// {
//     int row,col,r,c,q;
//     gotoxy(83,17);
//     SetConsoleTextAttribute(h,3);
//     printf("Loading...");
//     gotoxy(77,18);
//     SetConsoleTextAttribute(h,9);
//     for(r=1; r<=20; r++)
//     {
//         for(q=0; q<=100000000; q++); //To Print The Character Slowly
//         printf("%c",177);
//     }
//     printf("\n");
//     gotoxy(57,20);
//     SetConsoleTextAttribute(h,14);
//     printf("Loading Completed SuccessFully. Press Any Key To Continue");
//     getch();
//     system("cls");
// }
