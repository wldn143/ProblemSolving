#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, y, x, res, map[1001][1001], dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};
queue<pair<int, int>> q;

void bfs()
{
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

            if (map[ny][nx] == 0)
            {
                map[ny][nx] = map[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
                q.push({i, j});
        }

    bfs();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                cout << "-1";
                return 0;
            }
            res = max(res, map[i][j]);
        }
    }
    cout << res - 1;
}