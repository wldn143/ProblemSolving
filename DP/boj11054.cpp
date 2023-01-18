#include <iostream>
#include <algorithm>
using namespace std;
int n, a[1001], l[1001], r[1001], ret;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
                l[i] = max(l[i], l[j]);
        }
        l[i] += 1;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
                r[i] = max(r[i], r[j]);
        }
        r[i] += 1;
    }
    for (int i = 0; i < n; i++)
        ret = max(ret, l[i] + r[i]);
    cout << ret - 1 << "\n";
}