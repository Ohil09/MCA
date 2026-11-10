#include<iostream>
#include<fstream>
#include <cstring>
#include <cctype>
using namespace std;
int main() {
    int count = 0, alpha = 0, digit = 0;
    int space = 0, lines = 0;

    char filename[] = "file1.txt";
    char str[100];

    ofstream fout(filename);

    if (!fout) {
        cout << "Error creating file";
        return 1;
    }

    cout << "Enter multiple lines (type STOP to end):" << endl;

    while (true) {
        cin.getline(str, 100);

        if (strcmp(str, "STOP") == 0) {
            break;
        }

        fout << str << endl;
    }

    fout.close();

    ifstream file(filename);

    if (!file) {
        cout << "Error opening file";
        return 1;
    }

    while (file.getline(str, 100)) {
        lines++;

        for (int i = 0; str[i] != '\0'; i++) {
            count++;

            if (isalpha((unsigned char)str[i])) {
                alpha++;
            }

            if (isdigit((unsigned char)str[i])) {
                digit++;
            }

            if (str[i] == ' ') {
                space++;
            }
        }
    }

    file.close();

    cout << "\nTotal number of characters: " << count << endl;
    cout << "Total number of letters: " << alpha << endl;
    cout << "Total number of digits: " << digit << endl;
    cout << "Total number of lines: " << lines << endl;
    cout << "Total number of spaces: " << space << endl;

    return 0;
}
