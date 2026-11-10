#include <iostream>
using namespace std;

int main() {
    int bill, amt, change;
    int totalCoins = 0;

    cout << "Enter the bill amount: ";
    cin >> bill;

    cout << "Enter the amount given by the customer: ";
    cin >> amt;

    if (amt < bill) {
        cout << "Insufficient amount given." << endl;
        return 0;
    }

    change = amt - bill;

    cout << "Change to be returned: " << change << endl;
    cout << "Denominations: ";

    int denominations[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1};

    for (int i = 0; i < 9; i++) {
        int note = denominations[i];
        int count = change / note;

        for (int j = 0; j < count; j++) {
            cout << note << " ";
            totalCoins++;
        }

        change %= note;
    }

    cout << endl;
    cout << "Minimum number of notes/coins: " << totalCoins << endl;

    return 0;
}