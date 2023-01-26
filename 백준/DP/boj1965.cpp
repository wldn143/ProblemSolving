#include <iostream>
#include <algorithm>
using namespace std;
int n, k, a[1001], dp[1001], mx, ret;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        mx = 0;
        for (int j = i - 1; j >= 1; j--)
        {
            if (a[j] < a[i])
                mx = max(mx, dp[j]);
        }
        dp[i] = mx + 1;
        ret = max(dp[i], ret);
    }

    cout << ret << "\n";
}