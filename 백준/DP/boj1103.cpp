#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, m, a[54][54], check[51][51], dp[51][51], dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
int go(int y, int x)
{
    if (y < 0 || x < 0 || y >= n || x >= m || a[y][x] == 0)
        return 0;
    if (check[y][x])
    {
        cout << -1 << "\n";
        exit(0);
    }

    if (dp[y][x])
        return dp[y][x];

    check[y][x] = 1;
    int v = a[y][x];
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i] * v;
        int nx = x + dx[i] * v;
        dp[y][x] = max(go(ny, nx) + 1, dp[y][x]);
    }
    check[y][x] = 0;
    return dp[y][x];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == 'H')
                a[i][j] = 0;
            else
                a[i][j] = s[j] - '0';
        }
    }
    cout << go(0, 0) << "\n";
}
