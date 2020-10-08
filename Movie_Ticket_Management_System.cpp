#include <iostream>
#include<fstream>
#define ll long long int
using namespace std;


ofstream fout; //Create an Output Stream
ifstream fin; //Create an Input Stream

struct date{
    int dd;
    int mm;
    int yy;
};
struct date d;

struct timee{
    int hh;
    int min;
    int ss;
};

struct timee t;

class Movie{
    public:
    char MovieName[30];
    //date d;
    //timee t;
    char Venue[30];

    void UpdateDetails(){
        fout.open("MovieName.dat",ios::out);
        
        cout<<"\nEnter the Movie Name : ";
        cin>>MovieName;
        cout<<"\nReleasing Date(dd-mm-yy): ";
        cin>>d.dd>>d.mm>>d.yy;
        cout<<"\nReleasing Time(hh-mm-ss): ";
        cin>>t.hh>>t.min>>t.ss;
        cout<<"\nEnter the Venue : ";
        cin>>Venue;
        
        //write the data in the movies file.
        
        fout<<MovieName<<d.dd<<d.mm<<d.yy<<t.hh<<t.min<<t.ss<<Venue<<endl;
        
        //close the file
        fout.close();
    }
};

Movie m;

class Admin : public Movie{
    public:
    string Id;
    string Name;
    string Password;
    void AddMovieRecords(){
        UpdateDetails();
    }
    void UpdateMovieRecords(){
        UpdateDetails();
    }
    void DeleteMovieRecords(){
    }
        
        
    
};


class Visitor{
    public:
    string Name;
    void GetRegistered(){
        
    }
    void ViewMovies(){
        cout<<"\nMovie Name : "<<m.MovieName;
        cout<<"\nReleasing Date(dd-mm-yy) : "<<d.dd<<d.mm<<d.yy;
        cout<<"\nReleasing Time(hh-mm-ss): "<<t.hh<<t.min<<t.ss;
        cout<<"\nEnter the Venue : "<<m.Venue;
        
    }
    
};
Visitor v;

class Registered_User{
	public:
	int Id;
	char Name[25];
	ll PhNo;
	char Address[100];
	void Login();
	void Logout();
	void ViewMovies();
	void BookTicket();
	void MakePayment();
	void CancelTicket();
};

Registered_User r;

class BookTicket{
    public:
    int No_of_tickets_available;
    char MovieName[25];
    int ShowNo;
    char Venue;
    
    void UpdateSeatsAvailable();
    
};

BookTicket b;

class MakePayment{
    public:
    int Id;
    float Amount;
    int TransactionId;
    void ConfirmTransaction();
    void ReturnMoneyOnCancellation();
    
};

MakePayment mp;

int main (){
    m.UpdateDetails();
    
    int choice;
    cout<<"*****************************************************"<<endl;
    cout<<" [1] Log In" << endl;
    cout<<"  [2] Exit Application" << endl;
    cout<<"\n\nEnter your choice : ";
    cin>>choice;
    if(choice == 1){
        cout<<"***************LOGIN MENU*******************"<<endl;
        cout<<"\n1. Login as Visitor";
        cout<<"\n2. Login as Registered User";
        cout<<"\n3. Login as Admin";
        cout<<"\n4. Exit.";
        int option;
        cout<<"\nEnter your choice : ";
        cin>>option;
        if(option == 1){
            cout<<"\n1. Get Registered";
            cout<<"\n2. View Movies";
            cout<<"\n3. Exit";
            int ch;
            cout<<"\nEnter your choice : ";
            cin>>ch;
            if(ch == 1){
                /*int Id;
                string Name;
                ll PhNo;
                string Address;*/
                
                fout.open("RegisteredUser.dat",ios::out);
                
                cout<<"\nEnter Id : ";
                cin>>r.Id;
                cout<<"\nEnter your Name : ";
                cin>>r.Name;
                cout<<"\nEnter your Phone Number : ";
                cin>>r.PhNo;
                cout<<"\nEnter your Address : ";
                cin>>r.Address;
                
                //write the data entered by the user in the file.
                fout<<r.Id<<r.Name<<r.PhNo<<r.Address<<endl;
                fout.close();
                cout<<"\nRegistration Successful...!!!";
            }
            else if(ch == 2){
                cout<<"\n**********MOVIE MENU**********\n";
                fin.open("MovieName.dat",ios::in);
                fin.seekg(0); //to bring the pointer at the file beginning. 
                cout<<endl;
                while(!fin.eof()){
                    //get the values from the file.
                    fin.get(m.MovieName,30);
                    fin>>d.dd>>d.mm>>d.yy;
                    fin>>t.hh>>t.min>>t.ss;
                    fin.get(m.Venue,30);
                    
                    cout<<"\nMovie Name : "<<m.MovieName;
                    cout<<"\nReleasing Date(dd-mm-yy): "<<d.dd<<d.mm<<d.yy;
                    cout<<"\nReleasing Time(hh-mm-ss): "<<t.hh<<t.min<<t.ss;
                    cout<<"\nEnter the Venue : "<<m.Venue;
                }
                
            }
            else if(ch == 3){
                exit(0);
            }
            else{
                cout<<"Wrong Choice..!!";
            }
        }
        else if(option == 2){
        	int checkid,ctr=0;
        	cout<<"Enter your Id : ";
        	cin>>checkid;
        	fin.open("RegisteredUser.dat",ios::in);
        	 fin.seekg(0); //to bring the pointer at the file beginning. 
            cout<<endl;
            while(!fin.eof()){
                fin>>r.Id;
                if(r.Id==checkid){
                    ctr=1;
                    cout<<"\nLog in Successful...!!";
                    return 0;
                }
                cout<<"\nLogin failed..!!";
            }
            if(ctr == 1){
                int c;
                cout<<"\n************REGISTERED USER MENU*****************\n";
                cout<<"\n1. View Movies";
                cout<<"\n2. BookTicket";
                cout<<"\n3. MakePayment";
                cout<<"\n4. CancelTicket";
                cout<<"\n5. Logout";
                cout<<"\n6. exit";
                cout<<"Enter your Choice : ";
                cin>>c;
                if(c == 1){
                    
                fin.open("MovieName.dat",ios::in);
                fin.seekg(0); //to bring the pointer at the file beginning. 
                cout<<endl;
                while(!fin.eof()){
                    //get the values from the file.
                    fin.get(m.MovieName,30);
                    fin>>d.dd>>d.mm>>d.yy;
                    fin>>t.hh>>t.min>>t.ss;
                    fin.get(m.Venue,30);
                    
                    cout<<"\nMovie Name : "<<m.MovieName;
                    cout<<"\nReleasing Date(dd-mm-yy): "<<d.dd<<d.mm<<d.yy;
                    cout<<"\nReleasing Time(hh-mm-ss): "<<t.hh<<t.min<<t.ss;
                    cout<<"\nEnter the Venue : "<<m.Venue;
                }
                    
                }
                else if(c == 2){
                    
                }
                else if( c == 3){
                    
                }
                else if(c == 4){
                    
                    
                }
                else if(c == 5){
                    return 0;
                    
                }
                else if(c == 6){
                    exit(0);
                }
                else{
                    cout<<"\n Wrong Choice..!!";
                }
            }
        }
        else if(option == 3){
            
        }
        else if(option == 4){
            
        }
        else{
            cout<<"\n Wrong Choice...!!";
        }
    }
    else if(choice == 2){
        exit(0);
    }
    else{
        cout<<"\nWrong choice...!!!";
    }
    /*Start:
	DisplayHeader();
	int nCommand;
	cout << "  [1] Log In" << endl;
	cout << "  [2] Exit Application" << endl;
	cout << endl;
	cout << " Please select your comamnd: ";
	cin >> nCommand;
	switch (nCommand)
	{
		case 1:
			Login();
			goto Start;
		case 2:
			return;
		default:
			goto Start;
	}
}
    
    
    //object of class Movie.
    Movie m;
    
    
    fout.open("MovieName.dat", ios::out);
    cout<<"\nAdd Movie Records : ";
    
    m.UpdateDetails();
    fout<<m.MovieName<<endl;
    fout<<d.dd<<d.mm<<d.yy;
    fout<<t.hh<<t.min<<t.ss;
    fout<<m.Venue<<endl;
    fout.close();
    
    
    
    fout.open("MovieName.txt", ios::out);
    cout<<"\nAdd Movie Records : ";
    
    Admin a;
    a.AddMovieRecords();
    
    fout<<a.MovieName<<endl;
    fout<<d.dd<<d.mm<<d.yy;
    fout<<t.hh<<t.min<<t.ss;
    fout<<a.Venue<<endl;
    fout.close();
*/
    return 0;
}

