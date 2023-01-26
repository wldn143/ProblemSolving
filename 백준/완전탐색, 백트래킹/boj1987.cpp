#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int n, m, cnt, mx = 1;
char a[21][21];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
int visited[26];
void go(int y, int x, int cnt)
{
    mx = max(mx, cnt);
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        int next = a[ny][nx] - 65;
        if (visited[next])
            continue;
        visited[next] = 1;
        go(ny, nx, cnt + 1);
        visited[next] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int start = a[0][0] - 65;
    visited[start] = 1;
    go(0, 0, 1);
    cout << mx << "\n";
}
