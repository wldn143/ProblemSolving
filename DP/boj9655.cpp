#include <iostream>
using namespace std;
int n, dp[1001];
int main()
{
    cin >> n;
    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        if ((dp[i - 1] || dp[i - 3]) == 0)
            dp[i] = 1;
    }
    if (dp[n])
        cout << "SK\n";
    else
        cout << "CY\n";
}