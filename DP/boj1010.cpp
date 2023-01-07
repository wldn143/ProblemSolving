#include <iostream>
#include <string.h>
using namespace std;
long long t, n, m, dp[31][31];

long long go(int lv, int b)
{
    if (m - b < n - lv)
        return 0;
    if (lv == n)
        return 1;

    if (dp[lv][b])
        return dp[lv][b];

    for (int i = b + 1; i <= (m - (n - (b + 1))); i++)
    {
        dp[lv][b] += go(lv + 1, i);
    }
    return dp[lv][b];
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cout << go(0, 0) << "\n";
        memset(dp, 0, sizeof(dp));
    }
}