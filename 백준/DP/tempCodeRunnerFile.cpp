#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[1001][1001], dp[1001][1001], ret = -2;

int go(int y, int x)
{
    if (y < 1 || x < 1 || y > n || x > m || !a[y][x])
        return 0;

    if (dp[y][x] != -1)
        return dp[y][x];

    dp[y][x] = min(min(go(y + 1, x), go(y, x + 1)), go(y + 1, x + 1)) + 1;

    return dp[y][x];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%1d", &a[i][j]);
            dp[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ret = max(ret, go(i, j));
        }
    }

    cout << ret << "\n";
}