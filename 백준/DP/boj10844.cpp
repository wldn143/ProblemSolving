#include <iostream>
#include <algorithm>
using namespace std;
long long n, dp[101][10], ret;
static long mod = 1000000000;

long long go(int lv, int k)
{
    if (k > 9 || k < 0)
        return 0;

    if (lv == n)
        return 1;

    if (dp[lv][k])
        return dp[lv][k];

    dp[lv][k] += go(lv + 1, k - 1) + go(lv + 1, k + 1);

    return dp[lv][k] % mod;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= 9; i++)
        ret += go(1, i);
    cout << ret % mod << "\n";
}