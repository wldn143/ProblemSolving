#include <iostream>
#include <algorithm>
using namespace std;
long long n, dp[91][2];

long long go(int lv, int num)
{
    if (lv == n)
        return 1;

    if (dp[lv][num])
        return dp[lv][num];

    if (!num)
        dp[lv][num] += go(lv + 1, 1);
    dp[lv][num] += go(lv + 1, 0);

    return dp[lv][num];
}

int main()
{
    cin >> n;
    cout << go(1, 1) << "\n";
}