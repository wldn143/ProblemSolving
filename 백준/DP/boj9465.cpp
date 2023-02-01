#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t, n, k, map[2][100001], dp[2][100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n;
        int line = 0;
        while (line <= 1)
        {
            for (int i = 0; i < n; i++)
            {
                cin >> map[line][i];
            }
            line++;
        }
        dp[0][0] = map[0][0];
        dp[1][0] = map[1][0];
        dp[0][1] = map[0][1] + map[1][0];
        dp[1][1] = map[1][1] + map[0][0];

        for (int i = 2; i < n; i++)
        {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + map[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + map[1][i];
        }
        cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
    }
}