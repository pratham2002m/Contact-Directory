// Libraries Used :
#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
#include<time.h>

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
void userlogin();
int login();
void changepassword();
void newaccount();

// Classes 
class data1 ;

   HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


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
        out.open(file,std::ios::app);
        out<<"\nName : "<<name<<"\nMobile no : "<<number<<"\nProfession : "<<profession<<"\nCity : "<<city<<"\nAddress : "<<address<<endl;
        out.close();

    }
};


// Function to add data to contacts
void addcontact(){

    
   

    fflush(stdin);
    string name ;

    SetConsoleTextAttribute(h,2);
    cout<<"\nFull Name : "<<endl;
    SetConsoleTextAttribute(h,15);
    getline(cin,name);

    
    
    fflush(stdin) ;
    string number;
    SetConsoleTextAttribute(h,2);
    cout<<"Mobile Number : "<<endl;
    SetConsoleTextAttribute(h,15);
    cin>>number;

    fflush(stdin) ;
    string city;
    SetConsoleTextAttribute(h,2);
    cout<<"City : "<<endl;
    SetConsoleTextAttribute(h,15);
    cin>>city;

    fflush(stdin);
    string address;
    SetConsoleTextAttribute(h,2);
    cout<<"Address : "<<endl;
    SetConsoleTextAttribute(h,15);
    getline(cin,address);
    
    fflush(stdin);
    string profession;
    SetConsoleTextAttribute(h,2);
    cout<<"Profession : "<<endl;
    SetConsoleTextAttribute(h,15);
    getline(cin,profession) ;
    fflush(stdin);


    data1 cntdata(name,number,address,city,profession);
    // data cntdata(name,number,address,city,profession);
    cntdata.storedata();

    Sleep(1000);

    SetConsoleTextAttribute(h,4);
    cout<<"Data has been saved successfully !!!"<<endl;
    SetConsoleTextAttribute(h,15);

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
    
    SetConsoleTextAttribute(h,15);
   
    cout<<"\nChoose your action : \n\n";

    int action ;

    SetConsoleTextAttribute(h,5);
    cout<<"1. Add a contact"<<endl;
    cout<<"2. Remove a contact"<<endl;
    cout<<"3. Update a contact\n"<<endl;

    cin>>action;

    SetConsoleTextAttribute(h,15);

    switch (action)
{

    case 1:
        addcontact();
        break;
    
    case 2:
    {
        fflush(stdin);
        string name,city,number;

        SetConsoleTextAttribute(h,2);
   
        cout<<"\nName of user : ";
        SetConsoleTextAttribute(h,15);
        getline(cin,name);

        fflush(stdin);
        SetConsoleTextAttribute(h,2);
        cout<<"\nCity : ";
        SetConsoleTextAttribute(h,15);
        getline(cin,city);

        fflush(stdin);
        SetConsoleTextAttribute(h,12);
        cout<<"\nMobile no : ";
        SetConsoleTextAttribute(h,15);
        cin>>number ;

        fflush(stdin);
        removecontact(name,city,number);

        break;
    }
    case 3:
    {
        int action ;

        SetConsoleTextAttribute(h,4);
        cout<<"Choose the format : "<<endl;
        SetConsoleTextAttribute(h,15);
        cout<<"\n1.Name\n2.Mobile No.\n3.Profession\n\n";
        cin>>action;

        SetConsoleTextAttribute(h,15);
   

        string oldname, newname, old_number, new_number, oldcity, newcity, old_address,new_address, old_profession, new_profession ;

        fflush(stdin);

        SetConsoleTextAttribute(h,2);
        cout<<"\nCity : ";
        SetConsoleTextAttribute(h,15);
        getline(cin,oldcity);

        switch (action)
        {

        case 1:
            fflush(stdin);
            SetConsoleTextAttribute(h,2);
            cout<<"\nOld Name : ";
            SetConsoleTextAttribute(h,15);
            getline(cin,oldname);

            fflush(stdin);
            SetConsoleTextAttribute(h,2);
            cout<<"New Name : ";
            SetConsoleTextAttribute(h,15);
            getline(cin,newname);
            break;
        
       
        case 2:
            fflush(stdin);
            SetConsoleTextAttribute(h,2);
            cout<<"\nOld Mobile No : ";
            SetConsoleTextAttribute(h,15);
            getline(cin,old_number);

            fflush(stdin);
            SetConsoleTextAttribute(h,2);
            cout<<"New Mobile No : ";
            SetConsoleTextAttribute(h,15);
            getline(cin,new_number);
            break;
        
        case 3:
            fflush(stdin);
            SetConsoleTextAttribute(h,2);
            cout<<"\nOld Profession : ";
            SetConsoleTextAttribute(h,15);
            getline(cin,old_profession);

            fflush(stdin);
            SetConsoleTextAttribute(h,2);
            cout<<"New Profession : ";
            SetConsoleTextAttribute(h,15);
            getline(cin,new_profession);
            break;
        
       
        default:

            SetConsoleTextAttribute(h,4);
            cout<<"\nChoose the correct number !\n"<<endl;
            SetConsoleTextAttribute(h,15);
   
            updatecontact(oldname, newname, old_number, new_number, oldcity, newcity, old_address,new_address, old_profession, new_profession);
            break;
        }
        updatecontact(oldname, newname, old_number, new_number, oldcity, newcity, old_address,new_address, old_profession, new_profession);
        break;
    }
    default:

        SetConsoleTextAttribute(h,4);  
        cout<<"\nChoose the correct action!\n"<<endl;
        SetConsoleTextAttribute(h,15);
        adminoptions();
        break;
    
}


};

// Function for handling admin requests
void admin(){

     
   

    static int chances = 3 ;
    string password;

    SetConsoleTextAttribute(h,4);
    cout<<"Enter the password : ";
    SetConsoleTextAttribute(h,15);
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
            SetConsoleTextAttribute(h,4);
            admin();
        }
        else
        {
            SetConsoleTextAttribute(h,10);
            cout<<"\n Try again later!!! \n"<<endl;
            Sleep(2000);
            exit(1);
        }
        
       
      
    }
    
    

};



// This is a function to start the program
void start(){

    

    SetConsoleTextAttribute(h,12); 
    cout<<"\n\n\nWelcome To Contact Directory \n\n\n\n";


    SetConsoleTextAttribute(h,6); 
    cout<<"1. Admin\n";
    cout<<"2. User\n\n";
    SetConsoleTextAttribute(h,15); 
   

    int role ;
    SetConsoleTextAttribute(h,2); 
    cout<<"\nEnter your role : ";
    SetConsoleTextAttribute(h,15); 
    cin>>role;
    
    if (role == 1)
    {
        admin();
    }
    else
    {
        user();
    }

}


int main(){

    start();

    
     SetConsoleTextAttribute(h,6);
   
   char repeat ;
   cout<<"\n\nTRY AGAIN ? y/n : ";
   cin>>repeat;
   cout<<"\n\n";
   if (repeat == 'y')
   {
     SetConsoleTextAttribute(h,15);
      main();
   }

   

 return 0;
}



// User login,change password,signup features

int login(){
    string id,password,str;
    char change_password ;
    int check = 0;
    SetConsoleTextAttribute(h,6);
    cout<<"\nEnter your ID : ";
    SetConsoleTextAttribute(h,15);
    cin>>id;
    SetConsoleTextAttribute(h,6);
    cout<<"\nPassword : ";
    SetConsoleTextAttribute(h,15);
    cin>>password ;

    ifstream in("userdata.txt");
    ofstream out("temp.txt");
    getline(in,str);

    while (!in.eof())
    {
       if (str == "ID : " + id)
       {
           out<<str<<"\n";
           getline(in,str);
           if (str == "Password : " + password)
           {
                SetConsoleTextAttribute(h,6);
                cout<<"\nChange Password ? y/n \n";
                SetConsoleTextAttribute(h,15);
                cin>>change_password ;

               check = 1;
               if (change_password == 'y')
               {
                   string newpassword;
                   SetConsoleTextAttribute(h,6);
                   cout<<"Enter new password : ";
                   SetConsoleTextAttribute(h,15);
                   cin>>newpassword ;
                   out<<"Password : "<<newpassword<<"\n";
                   

               }
               else
               {
                   out<<str<<"\n";
               }
               

                getline(in,str);
                cout<<str<<"\n";
                out<<"\nLast login : "<<__DATE__<<" "<<__TIME__<<"\n";
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

    
    if (check == 1)
    {
        return 1;
    }
    

    return 0;
    
}

void newaccount(){

    string id,password ;

    SetConsoleTextAttribute(h,8);
    cout<<"\nCreate your ID : ";
    SetConsoleTextAttribute(h,15);
    cin>>id ;
    SetConsoleTextAttribute(h,8);
    cout<<"\nPassword : ";
    SetConsoleTextAttribute(h,15);
    cin>>password ;

    ofstream out("userdata.txt",ios::app);
    out<<"\nID : "<<id<<"\n";
    out<<"Password : "<<password<<"\n" ;
    out<<"Last login : "<<__DATE__<<" "<<__TIME__<<"\n";

    out.close();

    SetConsoleTextAttribute(h,2);
    cout<<"\n\n\n ********  Welcome To Contact - Directory  ******* \n\n ";
    exit(1);

}

void userlogin(){

    int choice;
    SetConsoleTextAttribute(h,6);
    cout<<"\n1.Login\n2.Create Account\n"<<endl;
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
                            cout<<"\n\nEnter the correct data !!!"<<endl;
                            cout<<"Only "<<c<<" chances left !!!"<<endl;
                            SetConsoleTextAttribute(h,15);
                        }
                        else
                        {
                            return ;
                        }
                        
                }
                
                    cout<<"Try Again Later"<<endl;
                    exit(1);
                
                break;
    }
    case 2:
        newaccount();
        break;
    
    default:
        break;
    }

}



void user(){

    userlogin();



    string city,name,profession,number;

    

    fflush(stdin);
    SetConsoleTextAttribute(h,2);
    cout<<"\n\nEnter the City : ";
    SetConsoleTextAttribute(h,15);
    getline(cin,city);

    ifstream in;
    string file = city.append(".txt");
    in.open(file);

    if (in.eof() == 0)
    {
        SetConsoleTextAttribute(h,8);
        cout<<"No such city found !!!"<<endl;
        SetConsoleTextAttribute(h,15);
        return ;
    }
    
 
    SetConsoleTextAttribute(h,4);
    cout<<"\n\nEnter info you know : \n"<<endl;

    int choice,flag=0 ;
    string str;
    string sname,snumber,sprofession; // To search by mobile and profession

    SetConsoleTextAttribute(h,9);
    cout<<"1.Name only\n2.Mobile No. only\n3.Profession only\n4.Name & Profession\n5.Name & Mobile No\n6.Profession & Mobile No\n7.Name,Mobile No,Profession\n"<<endl;
    SetConsoleTextAttribute(h,15);

    cin>>choice;
    cout<<"\n";

    switch (choice)
    {
    case 1:    // Name Only

        fflush(stdin);
    SetConsoleTextAttribute(h,2);
        cout<<"Enter the name : ";
    SetConsoleTextAttribute(h,15);
        getline(cin,name);

        getline(in,str);
        while (!in.eof())
        {
            if (str == "Name : " + name)
            {
                flag = 1 ;
                cout<<str<<"\n";
                getline(in,str);
                cout<<str<<"\n";
                getline(in,str);
                cout<<str<<"\n";
                getline(in,str);
                cout<<str<<"\n";
                getline(in,str);
                cout<<str<<"\n";
            }
            
            getline(in,str);
        }
        if (flag == 0)
        {
            SetConsoleTextAttribute(h,15);  
            cout<<"Data is not found !!!"<<endl;
        }
        
        break;
 
    case 2:   // Mobile No. only

        SetConsoleTextAttribute(h,2);  
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
                cout<<sname<<"\n";
                cout<<str<<"\n";
                getline(in,str);
                cout<<str<<"\n";
                getline(in,str);
                cout<<str<<"\n";
                getline(in,str);
                cout<<str<<"\n";
                
            }
                
               
             getline(in,str);
        }
            
            
        if (flag == 0)
        {
        SetConsoleTextAttribute(h,4);  
            cout<<"Data is not found !!!"<<endl;
        }
        
        break;
    case 3:              // Profession only

        getline(in,str);

        SetConsoleTextAttribute(h,2);  
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
            
            
            if (str == "Profession : " + profession)
            {
                flag = 1 ;

                cout<<sname<<endl;
                cout<<snumber<<endl;
                cout<<str<<"\n";
                getline(in,str);
                cout<<str<<"\n";
                getline(in,str);
                cout<<str<<"\n";
                
            }
            
            getline(in,str);
        }
        if (flag == 0)
        {
        SetConsoleTextAttribute(h,4);  
            cout<<"Data is not found !!!"<<endl;
        }
        
        break;
    
    case 4:      // Name & Profession

        SetConsoleTextAttribute(h,2);  
        cout<<"Enter the Name : ";
        SetConsoleTextAttribute(h,15);  
        fflush(stdin);
        getline(cin,name);

        SetConsoleTextAttribute(h,2);  
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

                        cout<<sname<<endl;
                        cout<<snumber<<endl; ;
                        cout<<str<<"\n";
                        getline(in,str);
                        cout<<str<<"\n";
                        getline(in,str);
                        cout<<str<<"\n";
                }
                
            }
            
            getline(in,str);
        }
        if (flag == 0)
        {
        SetConsoleTextAttribute(h,4);  
            cout<<"Data is not found !!!"<<endl;
        }
        
        break;

    case 5:       //  Name & Mobile No

        SetConsoleTextAttribute(h,2);  
        cout<<"Enter the Name : ";
        SetConsoleTextAttribute(h,15);  
        fflush(stdin);
        getline(cin,name);

        SetConsoleTextAttribute(h,2);  
        cout<<"Enter the Mobile No : ";
        SetConsoleTextAttribute(h,15);  
        fflush(stdin);
        getline(cin,number);

        getline(in,str);
        
        while (!in.eof())
        {

            if (str == "Name : " + name)
            {
                cout<<"Check1"<<endl;
                sname = str ;
                getline(in,str);
                fflush(stdin);
                if (str == "Mobile no : " + number)
                {
                        cout<<"Check2"<<endl;
                        flag = 1 ;
                        cout<<sname<<endl;
                        cout<<str<<"\n";
                        getline(in,str);
                        cout<<str<<"\n";
                        getline(in,str);
                        cout<<str<<"\n";
                        getline(in,str);
                        cout<<str<<"\n";
                }
                
            }
            
            getline(in,str);
        }
        if (flag == 0)
        {
        SetConsoleTextAttribute(h,4);  
            cout<<"Data is not found !!!"<<endl;
        }
        
        break;
    
    case 6:                // Profession & Mobile No

        SetConsoleTextAttribute(h,2);  
        cout<<"Enter the Mobile No : ";
        SetConsoleTextAttribute(h,15);  
        fflush(stdin);
        getline(cin,number);

        SetConsoleTextAttribute(h,2);  
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
                        cout<<sname<<endl;
                        cout<<snumber<<endl;
                        cout<<str<<"\n";
                        getline(in,str);
                        cout<<str<<"\n";
                        getline(in,str);
                        cout<<str<<"\n";
                }
                
            }

            sname = str ;
            
            getline(in,str);
        }
        if (flag == 0)
        {
            cout<<"Data is not found !!!"<<endl;
        }
        
        break;
    case 7:      // All 

        getline(in,str);

        SetConsoleTextAttribute(h,2);  
        cout<<"Enter the name : ";
        SetConsoleTextAttribute(h,15);  
        fflush(stdin);
        getline(cin,name);

        SetConsoleTextAttribute(h,2);  
        cout<<"Enter the Mobile No : ";
        SetConsoleTextAttribute(h,15);  
        fflush(stdin);
        getline(cin,number);

        SetConsoleTextAttribute(h,2);  
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
                        cout<<sname<<endl;
                        cout<<snumber<<endl;
                        cout<<str<<"\n";
                        getline(in,str);
                        cout<<str<<"\n";
                        getline(in,str);
                        cout<<str<<"\n";
                    }
                    
                }
                
            }
            
            getline(in,str);
        }
        if (flag == 0)
        {
        SetConsoleTextAttribute(h,4);  
            cout<<"Data is not found !!!"<<endl;
        }
        
        break;
    
    default:
        SetConsoleTextAttribute(h,4);  
        cout<<"Enter the correct option !!! ";
        SetConsoleTextAttribute(h,15);  
        user();
        break;
    }
    
    

    
}