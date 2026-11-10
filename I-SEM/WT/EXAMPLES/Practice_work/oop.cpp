
#include<iostream>
#include<fstream>
using namespace std;

class WaterBill {
    private:
        int code;
        char category;
        double water_bill;

    public:
        void getData(int c) {
            code = c;

            cout << "\nEnter Category (C - Company / I - Individual): ";
            cin >> category;

            cout << "Enter Water Bill: ";
            cin >> water_bill;
        }

        void display() {
            cout << "\nCustomer Code: " << code;
            cout << "\nCategory: " << category;
            cout << "\nWater Bill: " << water_bill;

            if(category == 'C') {
                double discount = water_bill * 0.10;

                cout << "\nDiscount: " << discount;
                cout << "\nFinal Bill: " << water_bill - discount;
            }
            else {
                cout << "\nDiscount: 0";
                cout << "\nFinal Bill: " << water_bill;
            }
            if(water_bill > 600){
                cout<<"\nToo much use !";
            }else if(water_bill >= 360 && water_bill <= 600){
                cout<<"\nModerate use !";
            }
            else{
                cout<<"\nGood usage well done!";
            }
        }

        int getCode() {
            return code;
        }

        double getBill() {
            return water_bill;
        }
};

int main() {
    WaterBill w, temp;
    int choice, searchCode;

    static int code = 0;

    // Find the highest existing customer code
    ifstream fin("water_details.txt", ios::binary);

    while(fin.read((char*)&temp, sizeof(temp))) {
        if(temp.getCode() > code) {
            code = temp.getCode();
        }
    }

    fin.close();

    do {
        cout << "\n\n========== WATER BILL MANAGEMENT ==========";
        cout << "\n1. Add Customer";
        cout << "\n2. Search Customer by Code";
        cout << "\n3. Display Total Water Bill";
        cout << "\n4. Exit";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {
                w.getData(code + 1);

                ofstream file("water_details.txt", ios::binary | ios::app);

                if(!file) {
                    cout << "\nUnable to open file!";
                    break;
                }

                file.write((char*)&w, sizeof(w));
                file.close();

                code++;

                cout << "\nCustomer added successfully!";
                cout << "\nCustomer Code: " << code;

                break;
            }

            case 2: {
                cout << "\nEnter Customer Code to Search: ";
                cin >> searchCode;

                ifstream file("water_details.txt", ios::binary);

                if(!file) {
                    cout << "\nUnable to open file!";
                    break;
                }

                int position = searchCode - 1;

                if(position < 0) {
                    cout << "\nInvalid Customer Code!";
                    file.close();
                    break;
                }

                file.seekg(position * sizeof(WaterBill), ios::beg);

                if(file.read((char*)&temp, sizeof(temp))) {
                    if(temp.getCode() == searchCode) {
                        cout << "\nCustomer Found!";
                        temp.display();
                    }
                    else {
                        cout << "\nCustomer Not Found!";
                    }
                }
                else {
                    cout << "\nCustomer Not Found!";
                }

                file.close();
                break;
            }

            case 3: {
                ifstream file("water_details.txt", ios::binary);

                if(!file) {
                    cout << "\nUnable to open file!";
                    break;
                }

                double total = 0;

                while(file.read((char*)&temp, sizeof(temp))) {
                    total += temp.getBill();
                }

                cout << "\nTotal Water Bill: " << total;

                file.close();
                break;
            }

            case 4:
                cout << "\nExiting...";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 4);

    return 0;
}