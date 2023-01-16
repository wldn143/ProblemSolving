#include <iostream>
#include <algorithm>
using namespace std;
int n, m, s, e, a[2001], dp[2001][2001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i][i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i + 1])
            dp[i][i + 1] = 1;
    }
    for (int i = 3; i <= n; i++)
    {
        for (int j = i - 2; j >= 1; j--)
        {
            if (a[i] == a[j] && dp[j + 1][i - 1])
                dp[j][i] = 1;
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }
}