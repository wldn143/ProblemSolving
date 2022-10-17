#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int n, m, k;
char a[5][5];
int v[5][5];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};
int res[26];
void go(int cnt, int y, int x)
{
    if (y == 0 && x == m - 1)
    {
        res[cnt]++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        if (v[ny][nx] || a[ny][nx] == 'T')
            continue;
        v[ny][nx] = 1;
        go(cnt + 1, ny, nx);
        v[ny][nx] = 0;
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    v[n - 1][0] = 1;
    go(1, n - 1, 0);

    cout << res[k] << "\n";
}
