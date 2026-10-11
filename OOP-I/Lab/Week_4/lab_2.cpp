#include<iostream>
using namespace std;
class bank{
    
    private:
        char cust_name[20];
        int account_no;
        char acc_type;
        float balance;
        
    public:
        bank(){
            account_no = 0;
            balance = 500;
        }
        
        void information_entry(){
            cout<<"Enter the account number : ";
            cin >> account_no;
            cout<<"Enter the account holder name : ";
            cin >> cust_name;
            cout<<"Enter the account type : ";
            cin >> acc_type;
            
        }
        void display_info(){
            cout<<"\n--------Account Details -----------";
            cout<<"\nAccount number : "<<account_no;
            cout<<"\nAccount holder name : "<<cust_name;
            cout<<"\nAccount type(Savings[S] / Current[C] / Fixed[F]) : "<<acc_type;
            cout<<"\nAccount balance : "<<balance;
                
        }
        void deposit(){
            float amount;
            cout<<"\nEnter the amount to deposit : ";
            cin>>amount;
            balance += amount;
            cout<<"\nAmount deposited successfully!";
        }
        friend void withdraw(bank &b);
};
void withdraw(bank &b){
    float amount;
    cout<<"\nEnter the amount to withdraw : ";
    cin>>amount;
    if(amount > b.balance){
        cout<<"\nInsufficient balance!";
    }
    else{
        b.balance -= amount;
        cout<<"\nAmount withdrawn successfully!";
    }
}
int main(){
    bank b1, b2;

    cout << "\nEnter details for Customer 1\n";
    b1.information_entry();
    b1.deposit();
    withdraw(b1);
    b1.display_info();


    cout << "\n\nEnter details for Customer 2\n";
    b2.information_entry();
    b2.deposit();
    withdraw(b2);
    b2.display_info();
    return 0;
}

