#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, y, x, k, l, ret;
const int INF = 987654321;
char a[1001][1001];
int visited[1001][1001];
int f_visited[1001][1001];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};
queue<pair<int, int>> q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    fill(&f_visited[0][0], &f_visited[0][0] + 1001 * 1001, INF);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'J')
            {
                k = i;
                l = j;
            }
            else if (a[i][j] == 'F')
            {
                f_visited[i][j] = 1;
                q.push({i, j});
            }
        }
    }

    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (a[ny][nx] == '#' || f_visited[ny][nx] != INF)
                continue;
            f_visited[ny][nx] = f_visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    visited[k][l] = 1;
    q.push({k, l});
    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();
        if (x == m - 1 || y == n - 1 || x == 0 || y == 0)
        {
            ret = visited[y][x];
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (a[ny][nx] == '#' || visited[ny][nx])
                continue;
            if (f_visited[ny][nx] <= visited[y][x] + 1)
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    if (ret != 0)
        cout << ret << "\n";
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}