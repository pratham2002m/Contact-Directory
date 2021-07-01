
// Libraries Used :
#include<bits/stdc++.h> 
#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>

using namespace std;

//  Functions 
void adminoptions();
void addcontact();
void removecontact();
void updatecontact();
void admin();
void user();
void start();
void storedata();

// Classes 
class data ;


class data{
    private :
    string name;
    string number ;
    string address ;
    string city ;
    string profession ;

    public :

    data(string name1,string num,string address1,string city1,string profession1){
        name = name1 ;
        number = num ;
        address = address1;
        city = city1;
        profession = profession1;

    }

    void storedata(){
        ofstream out;
        string file = city + ".txt";
        out.open(file,std::ios::app);
        out<<"\nName : "<<name<<"\nMobile no : "<<number<<"\nAddress : "<<address<<"\nCity : "<<city<<"\nProfession : "<<profession<<endl;
        out.close();

    }
};


// Function to add data to contacts
void addcontact(){

    fflush(stdin);
    string name ;
    cout<<"\nFull Name : "<<endl;
    getline(cin,name);

    
    
    fflush(stdin) ;
    string number;
    cout<<"Mobile Number : "<<endl;
    cin>>number;

    fflush(stdin) ;
    string city;
    cout<<"City : "<<endl;
    cin>>city;

    fflush(stdin);
    string address;
    cout<<"Address : "<<endl;
    getline(cin,address);
    
    fflush(stdin);
    string profession;
    cout<<"Profession : "<<endl;
    getline(cin,profession) ;

    data cntdata(name,number,address,city,profession);
    cntdata.storedata();

    Sleep(1000);
    cout<<"Data has been saved successfully !!!"<<endl;

}

void removecontact(string name,string city,string number){

    string str;
    ifstream in ;

    string tempfile = "temp.txt";
    ofstream out(tempfile) ;
    string file = city.append(".txt") ;
    in.open(file);
    getline(in,str);
    while (!in.eof())
    {
        if (str == "Name : " + name)
        {
             getline(in,str);
             if (str == "Mobile no : " + number)
             {
                 cout<<"\n\nData has been removed successfully !!!\n\n\n"<<endl;

                  // To delete address city profession
                getline(in,str); 
                getline(in,str);
                getline(in,str);
                getline(in,str);
                getline(in,str);

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
        
    }

    in.close();
    out.close();

    remove(file.c_str());
    rename("temp.txt",file.c_str());


}

void updatecontact(string oldname,string newname,string old_number,string new_number,string oldcity,string newcity,string old_address,string new_address,string old_profession,string new_profession){

    string str;
    ifstream in ;

    string tempfile = "temp.txt";
    ofstream out(tempfile) ;

    string file = oldcity.append(".txt") ;
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


// Function to provide options to admin for action
void adminoptions(){
    cout<<"Choose your action : \n\n\n";

    int action ;

    cout<<"1. Add a contact"<<endl;
    cout<<"2. Remove a contact"<<endl;
    cout<<"3. Update a contact\n"<<endl;

    cin>>action;


    switch (action)
{

    case 1:
        addcontact();
        break;
    
    case 2:
    {
        fflush(stdin);
        string name,city,number;
        cout<<"\nName of user : ";
        getline(cin,name);

        fflush(stdin);
        cout<<"\nCity : ";
        getline(cin,city);

        fflush(stdin);
        cout<<"\nMobile no : ";
        cin>>number ;

        fflush(stdin);
        removecontact(name,city,number);

        break;
    }
    case 3:
    {
        int action ;
        cout<<"Choose the format : "<<endl;
        cout<<"\n1.Name\n2.Mobile No.\n3.Profession\n\n";
        cin>>action;

        string oldname, newname, old_number, new_number, oldcity, newcity, old_address,new_address, old_profession, new_profession ;

        fflush(stdin);
        cout<<"\nCity : ";
        getline(cin,oldcity);

        switch (action)
        {

        case 1:
            fflush(stdin);
            cout<<"\nOld Name : ";
            getline(cin,oldname);

            fflush(stdin);
            cout<<"New Name : ";
            getline(cin,newname);
            break;
        
       
        case 2:
            fflush(stdin);
            cout<<"\nOld Mobile No : ";
            getline(cin,old_number);

            fflush(stdin);
            cout<<"New Mobile No : ";
            getline(cin,new_number);
            break;
        
        case 3:
            fflush(stdin);
            cout<<"\nOld Profession : ";
            getline(cin,old_profession);

            fflush(stdin);
            cout<<"New Profession : ";
            getline(cin,new_profession);
            break;
        
       
        default:
            cout<<"\nChoose the correct number !\n"<<endl;
            updatecontact(oldname, newname, old_number, new_number, oldcity, newcity, old_address,new_address, old_profession, new_profession);
            break;
        }
        updatecontact(oldname, newname, old_number, new_number, oldcity, newcity, old_address,new_address, old_profession, new_profession);
        break;
    }
    default:
        cout<<"\nChoose the correct action!\n"<<endl;
        adminoptions();
        break;
    
}


};

// Function for handling admin requests
void admin(){

    static int chances = 3 ;
    string password;
    cout<<"Enter the password : ";
    cin>>password ;
    if (password == "1234")
    {
        adminoptions();
    }
    else
    {
        chances--;
        if (chances != 0)
        {
            cout<<"\n Only "<<chances<<" chances left \n"<<endl;
            admin();
        }
        else
        {
            cout<<"\n Try again later!!! \n"<<endl;
            Sleep(2000);
            exit(1);
        }
        
       
      
    }
    
    

};



// This is a function to start the program
void start(){
    
    cout<<"Welcome To Contact Directory \n\n\n\n";
    cout<<"1. Admin\n";
    cout<<"2. User\n";
   

    int role ;
    cout<<"Enter your role : ";
    cin>>role;
    
    if (role == 1)
    {
        admin();
    }
    else
    {
        // user();
    }

}


int main(){

    start();
   
   char repeat ;
   cout<<"Want to do it again ? y/n : ";
   cin>>repeat;
   cout<<"\n\n";
   if (repeat == 'y')
   {
      main();
   }
   

 return 0;
}

void user(){
    string name;
    cout<<"Name to search : ";
    getline(cin,name);

    
}