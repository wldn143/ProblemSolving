#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, res, tmp, mn = 987654321, mx = -987654321;
queue<int> q;
int main()
{
    cin >> n;
    vector<int> a(n), v;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i <= 4; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
            v.push_back(i);
    }

    sort(v.begin(), v.end());

    do
    {
        for (int i = 0; i < n - 1; i++)
            q.push(v[i]);
        res = a[0];
        tmp = 0;
        for (int i = 1; i < n; i++)
        {
            int c = q.front();

            if (c == 1)
                res = res + a[i];
            else if (c == 2)
                res -= a[i];
            else if (c == 3)
                res *= a[i];
            else
                res /= a[i];
            q.pop();
        }
        mn = min(mn, res);
        mx = max(mx, res);
    } while (next_permutation(v.begin(), v.end()));
    cout << mx << "\n";
    cout << mn << "\n";
}
