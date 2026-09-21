#include<iostream>
using namespace std;
class person{
	private: 
		int id;
		char name[20];
	public:
		void read(){
			cout<<"\nEnter ID : ";
			cin>>id;
			cout<<"Enter name : ";
			cin.ignore();
			cin.getline(name, 20);
		}
		void display(){
			cout<<"\nID   : "<<id<<endl;
			cout<<"Name : "<<name<<endl;
		}
};
class teaching: public person{
	private: 
		char subject[20];
		char tName[20];
	public:
		void read(){
			person::read();
			cout<<"Enter Subject : ";
			cin.getline(subject, 20);
			cout<<"Enter Teacher name : ";
			cin.getline(tName,20);
		}
		void display(){
			person::display();
			cout<<"Subject      : "<<subject<<endl;
			cout<<"Teacher Name : "<<tName<<endl;
		}
};
class nonTeaching: public person{
	private: 
		char dept[20];
	public:
		void read(){
			person::read();
			cout<<"Enter Department : ";
			cin.getline(dept,20);
		}
		void display(){
			person::display();
			cout<<"Department  : "<<dept<<endl;
		}
};
class instructor: public person{
	private: 
		
	public:
		void read(){
			person::read();
		}
		void display(){
			person::display();
		}
};

int main(){

	int n,ch;
	
	cout<<"Enter the number of instructor : ";
	cin>>n;
	
	instructor in[n];
	
	do{
		cout<<"---------------------------\n";
		cout<<"1.Enter instructor \n";
		cout<<"2.Display instructor \n";
		cout<<"3.Exit\n";
		cout<<"---------------------------\n";
		cout<<"Enter your choice : ";
		cin>>ch;
		switch(ch){
			case 1:{
				for(int i = 0; i < n; i++){
					cout<<"\nEnter the Intructor "<<(i+1)<<" : ";
					in[i].read();
					cout<<"\n1 instructor has been Added !\n";
				}
				break;
			}
			case 2:{
				for(int i = 0; i < n; i++){
					cout<<"\nIntructor "<<(i+1)<<" : ";
					in[i].display();
				}
				break;
			}
			case 3:{
				cout<<"Exiting...";
				break;
			}
			default:
				cout<<"Please Enter an valid choice ! \n";	
		}
	}while(ch != 3);
	return 0;
}
