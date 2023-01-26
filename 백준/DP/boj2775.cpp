#include <iostream>
#include <algorithm>
using namespace std;
int t, k, n, dp[15][15];

int go(int a, int b)
{
    if (!a)
        return b;
    if (dp[a][b])
        return dp[a][b];
    for (int i = b; i >= 1; i--)
        dp[a][b] += go(a - 1, i);
    return dp[a][b];
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> k >> n;
        cout << go(k, n) << "\n";
    }
}