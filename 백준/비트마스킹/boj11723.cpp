#include <iostream>
using namespace std;
int n, x, a[21];
char s[11];
int main()
{
    cin >> n;
    while (n--)
    {
        scanf(" %s %d", &s, &x);
        if (s[0] == 'a' && s[1] == 'd')
            a[x] = 1;
        else if (s[0] == 'r')
            a[x] = 0;
        else if (s[0] == 'c')
        {
            if (a[x])
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (s[0] == 't')
        {
            if (a[x])
                a[x] = 0;
            else
                a[x] = 1;
        }
        else if (s[0] == 'a' && s[1] == 'l')
        {
            for (int i = 0; i < 21; i++)
            {
                a[i] = 1;
            }
        }
        else
        {
            for (int i = 0; i < 21; i++)
            {
                a[i] = 0;
            }
        }
    }
}
