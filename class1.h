#pragma once
#include<iostream>
#include<string> 
#include<fstream>
 

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std ;


class data1{
    private :
    string name;
    string number ;
    string address ;
    string city ;
    string profession ;

    public :

    data1(string name1,string num,string address1,string city1,string profession1){
        name = name1 ;
        number = num ;
        address = address1;
        city = city1;
        profession = profession1;

    }

    void storedata(){
        ofstream out;
        string file = city + ".txt";
        // string file ="\\City\\" +  city + ".txt";
        out.open(file,std::ios::app);
        out<<"\nName : "<<name<<"\nMobile no : "<<number<<"\nProfession : "<<profession<<"\nCity : "<<city<<"\nAddress : "<<address<<endl;
        out.close();

    }
};
