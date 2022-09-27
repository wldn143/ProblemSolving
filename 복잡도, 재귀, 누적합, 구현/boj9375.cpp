#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>

using namespace std;
int n, t;
string x, s;

int main()
{
    cin >> t;
    while (t--)
    {
        int cnt = 1;
        map<string, int> p;

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> s;
            p[s] += 1;
        }

        for (auto c : p)
        {
            cnt *= (c.second + 1);
        }
        cout << cnt - 1 << "\n";
    }
}