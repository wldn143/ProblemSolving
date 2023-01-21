#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int n, m, a[501][501], dp[501][501];
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

int dfs(int y, int x)
{
    if (y == n - 1 && x == m - 1)
        return 1;

    if (dp[y][x] != -1)
        return dp[y][x];

    dp[y][x] = 0;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= n || nx >= m || ny < 0 || nx < 0)
            continue;

        if (a[y][x] > a[ny][nx])
            dp[y][x] += dfs(ny, nx);
    }

    return dp[y][x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    memset(dp, -1, sizeof(dp));

    int ret = dfs(0, 0);
    if (ret == -1)
        cout << 0 << "\n";
    else
        cout << ret << "\n";
}