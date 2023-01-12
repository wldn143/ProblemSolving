#include <iostream>
#include <string.h>
using namespace std;
int n, a[101][101];
long long dp[101][101];

long long go(int y, int x)
{
    if (y == n - 1 && x == n - 1)
        return 1;
    if (y >= n || x >= n || !a[y][x])
        return 0;
    if (dp[y][x] != -1)
        return dp[y][x];
    return dp[y][x] = go(y + a[y][x], x) + go(y, x + a[y][x]);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0) << "\n";
}