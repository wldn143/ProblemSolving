#include <iostream>
#include <algorithm>
using namespace std;
int n, m, tmp, a[10], minimum;

int check(int now)
{
    string s = to_string(now);
    for (int i = 0; i < s.length(); i++)
    {
        if (a[s[i] - 48])
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        a[tmp] = 1;
    }

    minimum = abs(n - 100);
    string st = to_string(n);

    for (int i = 0; i <= 1000000; i++)
    {
        if (check(i))
        {
            tmp = abs(n - i) + to_string(i).length();
            minimum = min(minimum, tmp);
        }
    }
    cout << minimum << "\n";
}