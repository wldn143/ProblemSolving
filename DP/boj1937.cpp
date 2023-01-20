#include <iostream>
#include <algorithm>
using namespace std;
int n, a[501][501], dp[501][501], ret;
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

int dfs(int y, int x)
{
    if (dp[y][x])
        return dp[y][x];

    dp[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= n || nx >= n || ny < 0 || nx < 0)
            continue;

        if (a[y][x] < a[ny][nx])
            dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
    }

    return dp[y][x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ret = max(ret, dfs(i, j));

    cout << ret << "\n";
}