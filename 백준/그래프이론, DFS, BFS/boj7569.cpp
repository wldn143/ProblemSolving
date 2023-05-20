#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
int m, n, h;
int box[101][101][101];
int visited[101][101][101];
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
int res;
queue<tuple<int, int, int>> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> h;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
            {
                cin >> box[i][j][k]; // 층 세로 가로
                if (box[i][j][k] == 1)
                    q.push({i, j, k});
            }

    while (q.size())
    {
        int x, y, z;
        tie(z, y, x) = q.front();
        int cnt = box[z][y][x];
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (box[z][ny][nx] == 0)
            {
                box[z][ny][nx] = cnt + 1;
                q.push({z, ny, nx});
            }
        }

        if (z + 1 < h) // 위층
        {
            if (box[z + 1][y][x] == 0)
            {
                box[z + 1][y][x] = cnt + 1;
                q.push({z + 1, y, x});
            }
        }

        if (z - 1 >= 0) // 아래층
        {
            if (box[z - 1][y][x] == 0)
            {
                box[z - 1][y][x] = cnt + 1;
                q.push({z - 1, y, x});
            }
        }
        q.pop();
    }

    bool flag = 1;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                res = max(res, box[i][j][k]);
                if (box[i][j][k] == 0)
                {
                    flag = 0;
                    i = h;
                    break;
                }
            }
        }
    }

    if (flag)
        cout << res - 1;
    else
        cout << -1;
}