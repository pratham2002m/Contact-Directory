#include<iostream>
#include<fstream>
#include<string>

void updatecontact(string oldname,string newname,string old_number,string new_number,string oldcity,string newcity,string old_address,string new_address,string old_profession,string new_profession){

    string str;
    ifstream in ; 

    string tempfile = "temp.txt";
    ofstream out(tempfile) ;

    
   

    string file =  oldcity.append(".txt") ;
    in.open(file);

    getline(in,str);

    while (!in.eof())
    {
        if (str == "Name : " + oldname)
        {
            out<<"Name : " + newname<<"\n" ;    
            getline(in,str);
        }

        if (str == "Mobile no : " + old_number)
        {
            out<<"Mobile no : " + new_number<<"\n" ; 
            getline(in,str);   
        }

        if (str == "Address : " + old_address)
        {
            out<<"Address : " + new_address<<"\n" ;    
            getline(in,str);
        }

        if (str == "Profession : " + old_profession)
        {
            out<<"Profession : " + new_profession<<"\n" ;    
            getline(in,str);
        }

       
        out<<str<<"\n";
        getline(in,str);
        
    }

    in.close();
    out.close();

    remove(file.c_str());
    rename("temp.txt",file.c_str());
}


