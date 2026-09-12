#include<iostream>
#include<string>
using namespace std;

struct emp{
	int emp_no;
	string emp_name;
	float basic;
	float da;
	float gross_sal;
	float it;
	float net_sal;
};
void read(struct emp &e){
	cout<<"\nEnter the Employee Number : ";
	cin>>e.emp_no;
	cout<<"Enter the Employee Name : ";
	cin>>e.emp_name;
	cout<<"Enter the Basic sal : ";
	cin>>e.basic;
}

void display(struct emp &e){
	cout<<"\n------------------------------------------------------------------";
	cout<<"\nEmployee details of : "<<e.emp_name;
	cout<<"\nEmployee Number : "<<e.emp_no;
	cout<<"\nEmployee Basic salary : "<<e.basic;
	cout<<"\nEmployee DA : "<<e.da;
	cout<<"\nEmployee IT : "<<e.it;
	cout<<"\nEmployee Net Salary : "<<e.net_sal;
	cout<<"\n------------------------------------------------------------------";
}
void calculate(struct emp &e){
	e.da = e.basic * 0.12;
	e.gross_sal = e.basic + e.da ;
	e.it = e.gross_sal * 0.18;
	e.net_sal = e.gross_sal - e.it; 
}
int main(){
	int n;
	cout<<"Enter the number of employee : ";
	cin>>n;
	struct emp e[n];
	for(int i = 0; i < n; i++){
		cout<<"\nEnter details for Employee : "<<(i+1);
		read(e[i]);
		calculate(e[i]);
	}
	cout<<"---------------------- Employee Details ------------------------\n";
	for(int i = 0; i < n; i++){
		display(e[i]);
	}
	return 0;
}
