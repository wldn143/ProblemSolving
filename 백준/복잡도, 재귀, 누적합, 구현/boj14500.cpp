#include <iostream>
#include <algorithm>
using namespace std;
int n, m, result;
int map[501][501], visited[501][501];
int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void check(int y, int x)
{
    if (y + 1 < n && x + 2 < m)
        result = max(result, map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 1]);
    // ㅏ
    if (y + 2 < n && x + 1 < m)
        result = max(result, map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 2][x]);
    // ㅗ
    if (y - 1 >= 0 && x + 2 < m)
        result = max(result, map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y - 1][x + 1]);
    // ㅓ
    if (y + 2 < n && x - 1 >= 0)
        result = max(result, map[y][x] + map[y + 1][x] + map[y + 1][x - 1] + map[y + 2][x]);
    return;
}

void dfs(int y, int x, int w, int sum)
{
    if (w == 4)
    {
        result = max(result, sum);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int ny = y + d[i][0];
        int nx = x + d[i][1];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx])
            continue;
        visited[ny][nx] = 1;
        dfs(ny, nx, w + 1, sum + map[ny][nx]);
        visited[ny][nx] = 0;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            check(i, j);
            visited[i][j] = 1;
            dfs(i, j, 1, map[i][j]);
            visited[i][j] = 0;
        }
    }

    cout << result;
}