#include <iostream>
#include <set>
using namespace std;
int n, m, a[51][51], visited[51][51], visited2[51][51], room[51][51], rno, r_cnt[2504], res2, res3;
set<int> v[2504];
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
void dfs(int y, int x)
{
    visited[y][x] = 1;
    room[y][x] = rno;
    r_cnt[rno]++;
    for (int i = 0; i < 4; i++)
    {
        if (!(a[y][x] & (1 << i)))
        {
            if (i == 0 && x - 1 >= 0 && !visited[y][x - 1])
                dfs(y, x - 1);
            if (i == 1 && y - 1 >= 0 && !visited[y - 1][x])
                dfs(y - 1, x);
            if (i == 2 && x + 1 < m && !visited[y][x + 1])
                dfs(y, x + 1);
            if (i == 3 && y + 1 < n && !visited[y + 1][x])
                dfs(y + 1, x);
        }
    }
}

void dfs2(int y, int x)
{
    visited2[y][x] = 1;
    int r = room[y][x];
    for (int i = 0; i < 4; i++)
    {
        int ny = dy[i] + y, nx = dx[i] + x;
        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        if (room[y][x] != room[ny][nx])
            v[r].insert(room[ny][nx]);
        if (visited2[ny][nx])
            continue;
        dfs2(ny, nx);
    }
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                dfs(i, j);
                rno++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited2[i][j])
            {
                dfs2(i, j);
            }
        }
    }

    for (int i = 0; i < rno; i++)
    {
        res2 = max(res2, r_cnt[i]);
        for (int x : v[i])
        {
            res3 = max(res3, r_cnt[i] + r_cnt[x]);
        }
    }
    cout << rno << "\n"
         << res2 << "\n"
         << res3 << "\n";
}
