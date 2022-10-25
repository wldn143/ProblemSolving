#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int flag, hop;
string s1, s2, res;
vector<int> a, b;
int main()
{
    cin >> s1 >> s2;
    int l1 = s1.length(), l2 = s2.length(), l = max(l1, l2);
    for (char c : s1)
    {
        a.push_back(c - '0');
    }
    for (char c : s2)
    {
        b.push_back(c - '0');
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < abs(l1 - l2); i++)
    {
        if (l1 > l2)
            b.push_back(0);

        else
            a.push_back(0);
    }

    for (int i = 0; i < l; i++)
    {
        int x = a[i], y = b[i];
        if (flag)
            hop = x + y + 1;
        else
            hop = x + y;

        if (hop >= 10)
        {
            res += to_string(hop - 10);
            flag = 1;
            if (i == l - 1)
                res += "1";
        }
        else
        {
            res += to_string(hop);
            flag = 0;
        }
    }
    reverse(res.begin(), res.end());
    cout << res << "\n";
}