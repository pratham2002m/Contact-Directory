#include<iostream>
#include<windows.h> 
#include<fstream>
#include<string>
#include<conio.h> 

 
#include "gotoxy.h"
#include "class1.h"

void removecontact(string name,string city,string number){

    string str;
    ifstream in ;

    string tempfile = "temp.txt";
    ofstream out(tempfile) ;
    string file = "\\City\\" + city.append(".txt") ;
    in.open(file);
    getline(in,str);
    while (!in.eof())
    {
        if (str == "Name : " + name)
        {
             getline(in,str);
             if (str == "Mobile no : " + number)
             {
                 SetConsoleTextAttribute(h,11);
                 gotoxy(71,28);
                 cout<<"Data has been removed successfully !!!\n\n\n"<<endl;

                  // To delete address city profession
                getline(in,str); 
                getline(in,str);
                getline(in,str);
                getline(in,str);
                getline(in,str);
                gotoxy(30,30);
             }
             else       // If mobile number is not same
             {
                 out<<str<<"\n";

                 getline(in,str);
                 out<<str<<"\n";

                 getline(in,str);
                 out<<str<<"\n";

                 getline(in,str);
                 out<<str<<"\n";

                 getline(in,str);
                 out<<str<<"\n";

                 
                
             }
             
        }
       
         out<<str<<"\n";
         getline(in,str); 
         gotoxy(30,30);
    }

    in.close();
    out.close();

    remove(file.c_str());
    rename("temp.txt",file.c_str());


}
