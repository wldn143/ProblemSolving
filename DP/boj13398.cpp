#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100001], m, dp[100001][2], ret;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    dp[0][0] = a[0];
    dp[0][1] = a[0];
    ret = a[0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(a[i], dp[i - 1][0] + a[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + a[i]);
        ret = max(ret, max(dp[i][0], dp[i][1]));
    }
    cout << ret << "\n";
}