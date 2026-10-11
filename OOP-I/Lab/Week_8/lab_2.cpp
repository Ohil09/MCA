#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
protected:
    char name[30];
    int code;

public:
    void getEmployee()
    {
        cout << "Enter Employee Name: ";
        cin >> name;

        cout << "Enter Employee Code: ";
        cin >> code;
    }

    void displayEmployee()
    {
        cout << "Name       : " << name << endl;
        cout << "Code       : " << code << endl;
    }
};

class Account : virtual public Employee
{
protected:
    float pay;

public:
    void getAccount()
    {
        cout << "Enter Pay: ";
        cin >> pay;
    }

    void displayAccount()
    {
        cout << "Pay        : " << pay << endl;
    }
};

class Admin : virtual public Employee
{
protected:
    int experience;

public:
    void getAdmin()
    {
        cout << "Enter Experience: ";
        cin >> experience;
    }

    void displayAdmin()
    {
        cout << "Experience : " << experience << " years" << endl;
    }
};

class Master : public Account, public Admin
{
public:
    void getData()
    {
        getEmployee();
        getAccount();
        getAdmin();
    }

    void displayData()
    {
        cout << "\n----- MASTER DETAILS -----" << endl;

        displayEmployee();
        displayAccount();
        displayAdmin();
    }

    void updateData()
    {
        cout << "\nEnter updated details:" << endl;

        getEmployee();
        getAccount();
        getAdmin();
    }
};

int main()
{
    Master m;

    // Create and initialize Master object
    cout << "Enter Employee Details:" << endl;
    m.getData();

    // Display
    cout << "\nInitial Details:" << endl;
    m.displayData();

    // Update
    cout << "\nUpdate Master Details" << endl;
    m.updateData();

    // Display updated information
    cout << "\nUpdated Details:" << endl;
    m.displayData();

    return 0;
}