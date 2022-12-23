#include <iostream>
#include <algorithm>
using namespace std;
int dp[10001], n, k, temp;
int main()
{
    cin >> n >> k;
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp > 10000)
            continue;
        for (int j = temp; j <= k; j++)
        {
            dp[j] += dp[j - temp];
        }
    }
    cout << dp[k] << "\n";
}
