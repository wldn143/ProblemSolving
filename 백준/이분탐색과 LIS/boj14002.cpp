#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int n, res = 1, a[1001], c[1001];
stack<int> s;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        c[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                c[i] = max(c[j] + 1, c[i]);
                res = max(res, c[i]);
            }
        }
    }
    cout << res << "\n";
    for (int i = n - 1; i >= 0; i--)
    {
        if (c[i] == res)
        {
            s.push(a[i]);
            res--;
        }
    }
    while (s.size())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}