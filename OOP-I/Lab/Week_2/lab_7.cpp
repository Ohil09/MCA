#include<iostream>
using namespace std;
struct bank{
	string cust_name, acc_type;
	int acc_no,bal_amt;
};
int main(){
	bank accs;
	int ch;
	cout<<"Enter customer name of cust 1 : ";
	cin >> ws;
    getline(cin, accs.cust_name);
	
	cout<<"Enter acc number : ";
	cin>>accs.acc_no;
	
	cout<<"Enter acc type : ";
	cin>>accs.acc_type;
	
	cout<<"Enter balance amount : ";
	cin>>accs.bal_amt;
	
	
	while(true){	
		cout<<"\n\n1.Deposit \n2.Withdraw \n3.Check amount \n4.Exit \nEnter your choice : ";
		cin>>ch;
		switch(ch){
			case 1:{
				int amt;
				cout<<"\nEnter an amount to deposit : ";
				cin>>amt;
				if(amt <= 0){
					cout<<"Invalid amout!";
				}else{
					accs.bal_amt += amt;
					cout<<"Deposited successfully!";
				}
				break;
			}
			case 2:{
				int amt;
				cout<<"\nEnter an amount to Withdraw : ";
				cin>>amt;
				if(amt <= 0){
					cout<<"Invalid amout!";
				}
				else if(accs.bal_amt - amt >= 0){
					accs.bal_amt -= amt;
					cout<<"Withdrew successfully!";
				}else{
					cout<<"Insufficient Amount !";
				}
				break;
			}
			case 3:{
				cout<<"\nDisplay acc details : \n";
				cout << "\nCustomer Name: " << accs.cust_name << "\n";
				cout << "Account Number: " << accs.acc_no << "\n";
				cout << "Account type : " << accs.acc_type << "\n";
				cout << "Balance : " << accs.bal_amt << "\n";
				break;
			}
			case 4:{
				return 0;
			}
			default:
				cout<<"Enter an valid choice : ";
		}
	}
	return 0;
}
