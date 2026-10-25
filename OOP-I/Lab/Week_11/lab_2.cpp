#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Item
{
    char name[30];
    int code;
    float price;
    int quantity;

public:
    void getData(int c)
    {
        code = c;

        cout << "Enter Item Name: ";
        cin.ignore();
        cin.getline(name, 30);

        cout << "Enter Unit Price: ";
        cin >> price;

        cout << "Enter Quantity on Hand: ";
        cin >> quantity;
    }

    void display()
    {
        cout << "\nItem Code     : " << code;
        cout << "\nItem Name     : " << name;
        cout << "\nUnit Price    : " << price;
        cout << "\nQuantity      : " << quantity << endl;
    }

    int getCode()
    {
        return code;
    }
};

int main()
{
    Item item, temp;
    fstream file;
    int choice, code, nextCode;

    do
    {
        cout << "\n1. Add New Record";
        cout << "\n2. Modify Existing Record";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            nextCode = 1;

            file.open("item.dat", ios::in | ios::binary);

            if(file)
            {
                while(file.read((char*)&temp, sizeof(temp)))
                {
                    if(temp.getCode() >= nextCode)
                        nextCode = temp.getCode() + 1;
                }
                file.close();
            }

            item.getData(nextCode);

            file.open("item.dat", ios::out | ios::app | ios::binary);

            file.write((char*)&item, sizeof(item));
            file.close();

            cout << "Record added successfully.";
            cout << "\nGenerated Item Code: " << nextCode << endl;
        }
        else if(choice == 2)
        {
            cout << "Enter Item Code to Modify: ";
            cin >> code;

            file.open("item.dat", ios::in | ios::out | ios::binary);

            if(!file)
            {
                cout << "No item records found.\n";
                continue;
            }

            file.seekg(0, ios::beg);

            bool found = false;

            while(file.read((char*)&temp, sizeof(temp)))
            {
                if(temp.getCode() == code)
                {
                    found = true;

                    cout << "\nExisting Record:";
                    temp.display();

                    item.getData(code);

                    file.seekp(-((int)sizeof(Item)), ios::cur);
                    file.write((char*)&item, sizeof(item));

                    cout << "\nRecord modified successfully.\n";
                    break;
                }
            }

            if(!found)
                cout << "Item code not found.\n";

            file.close();
        }
        else if(choice != 3)
        {
            cout << "Invalid choice.\n";
        }

    } while(choice != 3);

    return 0;
}
