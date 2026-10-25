#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class Employee
{
    int empId;
    char name[30], dept[20], designation[20];
    float basic, da, hra, gross, tax, net;

public:
    void getData(int id)
    {
        empId = id;

        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 30);

        cout << "Enter Department: ";
        cin.getline(dept, 20);

        cout << "Enter Designation: ";
        cin.getline(designation, 20);

        cout << "Enter Basic Salary: ";
        cin >> basic;
    }

    void calculate()
    {
        da = basic * 0.50;
        hra = basic * 0.20;
        gross = basic + da + hra;
        tax = gross * 0.10;
        net = gross - tax;
    }

    void displaySlip()
    {
        calculate();

        cout << fixed << setprecision(2);
        cout << "\n========== SALARY SLIP ==========\n";
        cout << "Employee ID   : " << empId << endl;
        cout << "Name          : " << name << endl;
        cout << "Department    : " << dept << endl;
        cout << "Designation   : " << designation << endl;
        cout << "Basic Salary  : " << basic << endl;
        cout << "DA            : " << da << endl;
        cout << "HRA           : " << hra << endl;
        cout << "Gross Pay     : " << gross << endl;
        cout << "Income Tax    : " << tax << endl;
        cout << "Net Pay       : " << net << endl;
        cout << "=================================\n";
    }

    int getId()
    {
        return empId;
    }
};

int main()
{
    Employee e;
    fstream file;
    int choice, id;
    int nextId = 1;

    do
    {
        cout << "\n1. Add Employee";
        cout << "\n2. Generate Salary Slip";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            // Generate ID automatically
            file.open("employee.dat",ios::in | ios::binary);
            if(file)
            {
                Employee temp;
                while(file.read((char*)&temp, sizeof(temp)))
                {
                    if(temp.getId() >= nextId)
                        nextId = temp.getId() + 1;
                }
                file.close();
            }

            e.getData(nextId);

            file.open("employee.dat", ios::in | ios::out | ios::binary);
            if(!file)
            {
                file.clear();
                file.open("employee.dat", ios::out | ios::binary);
                file.close();

                file.open("employee.dat", ios::in | ios::out | ios::binary);
            }

            file.seekp(0, ios::end);
            file.write((char*)&e, sizeof(e));
            file.close();

            cout << "Employee added. ID = " << nextId << endl;
        }
        else if(choice == 2)
        {
            cout << "Enter Employee ID: ";
            cin >> id;

            file.open("employee.dat", ios::in | ios::binary);

            if(!file)
            {
                cout << "No employee records found.\n";
                continue;
            }

            file.seekg((id - 1) * sizeof(Employee), ios::beg);
			
			if(file.read((char*)&e, sizeof(e)) && e.getId() == id)
			{
			    e.displaySlip();
			}
			else
			{
			    cout << "Employee not found.\n";
			}

            file.close();
        }
        else if(choice != 3)
        {
            cout << "Invalid choice.\n";
        }

    } while(choice != 3);

    return 0;
}
