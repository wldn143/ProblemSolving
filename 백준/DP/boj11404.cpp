#include <iostream>
#include <algorithm>
using namespace std;
#define INF 10000001

int dp[101][101];
int n, m, a, b, c;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                dp[i][j] = INF;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dp[i][j] == INF)
                cout << 0 << " ";
            else
                cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}
