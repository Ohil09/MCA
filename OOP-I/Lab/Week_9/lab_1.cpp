#include <iostream>
using namespace std;

class Employee
{
protected:
    int code;
    char name[20];

public:
    void getEmp()
    {
        cout << "Enter Employee Code: ";
        cin >> code;

        cout << "Enter Employee Name: ";
        cin >> name;
    }

    void displayEmp()
    {
        cout << "Employee Code: " << code << endl;
        cout << "Employee Name: " << name << endl;
    }
};

class Education
{
protected:
    char qualification[30];

public:
    void getEdu()
    {
        cout << "Enter Qualification: ";
        cin.ignore();
        cin >> qualification;
    }

    void displayEdu()
    {
        cout << "Qualification: " << qualification << endl;
    }
};

class Laborer : public Employee
{
protected:
    float pay;

public:
    void getLaborer()
    {
        cout << "Enter Laborer Pay: ";
        cin >> pay;
    }

    void displayLaborer()
    {
        displayEmp();
        cout << "Laborer Pay: " << pay << endl;
    }
};

class Scientist : public Employee, public Education
{
protected:
    float pay;

public:
    void getScientist()
    {
        getEmp();
        getEdu();

        cout << "Enter Scientist Pay: ";
        cin >> pay;
    }

    void displayScientist()
    {
        displayEmp();
        displayEdu();
        cout << "Scientist Pay: " << pay << endl;
    }
};

class Manager : public Employee, public Education
{
protected:
    float pay;

public:
    void getManager()
    {
        getEmp();
        getEdu();

        cout << "Enter Manager Pay: ";
        cin >> pay;
    }

    void displayManager()
    {
        displayEmp();
        displayEdu();
        cout << "Manager Pay: " << pay << endl;
    }
};

int main()
{
    Laborer l;
    Scientist s;
    Manager m;

    cout << "\n----- ENTER LABORER DETAILS -----\n";
    l.getEmp();
    l.getLaborer();

    cout << "\n----- ENTER SCIENTIST DETAILS -----\n";
    s.getScientist();

    cout << "\n----- ENTER MANAGER DETAILS -----\n";
    m.getManager();

    cout << "\n\n========== DETAILS ==========\n";

    cout << "\n--- Laborer ---\n";
    l.displayLaborer();

    cout << "\n--- Scientist ---\n";
    s.displayScientist();

    cout << "\n--- Manager ---\n";
    m.displayManager();

    return 0;
}
