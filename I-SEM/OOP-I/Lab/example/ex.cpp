
#include<iostream>
#include<cstring>
using namespace std;

class mystring
{
    char str[100];

public:
    mystring(char s[] = "")
    {
        strcpy(str, s);
    }

    void input()
    {
        cin >> str;
    }

    void operator++()
    {
        char vow[5] = {'a', 'e', 'i', 'o', 'u'};
        int count = 0;

        for(int i = 0; str[i] != '\0'; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(str[i] == vow[j])
                {
                    count++;
                    break;
                }
            }
        }

        cout << "Number of vowels: " << count << endl;
    }
};

int main()
{
    mystring s1;

    cout << "Enter a string: ";
    s1.input();

    ++s1;

    return 0;
}
