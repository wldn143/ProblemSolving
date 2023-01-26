#include <iostream>
#include <string>
using namespace std;
int no;
string s;
int main()
{
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'p' && (s.length() - i) >= 2)
        {
            if (s[i + 1] == 'i')
                i += 1;

            else
            {
                no = 1;
            }
        }

        else if (s[i] == 'k' && (s.length() - i) >= 2)
        {
            if (s[i + 1] == 'a')
            {
                i += 1;
                continue;
            }

            else
                no = 1;
        }

        else if (s[i] == 'c' && (s.length() - i) >= 3)
        {
            if (s[i + 1] == 'h' && s[i + 2] == 'u')
                i += 2;
            else
                no = 1;
        }
        else
            no = 1;
    }
    if (no)
        cout << "NO\n";
    else
        cout << "YES\n";
}
