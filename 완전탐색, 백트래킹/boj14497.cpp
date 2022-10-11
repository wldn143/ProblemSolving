#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
int n, m, x1, y1, x2, y2, x, y, zy, zx;
char c;
int a[302][302];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
int visited[302][302];
int res = 100000000;
queue<pair<int, int>> q;
queue<pair<int, int>> zero;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c;
            if (c == '#')
                a[i][j] = 100; //목적지
            else if (c == '*')
                a[i][j] = 2; //시작
            else
                a[i][j] = c - '0';
        }
    }
    visited[y1][x1] = 1;
    q.push({y1, x1});

    while (q.size())
    {
        tie(y, x) = q.front();
        a[y][x] = 0;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny <= 0 || nx <= 0 || ny > n || nx > m)
                continue;
            if (visited[ny][nx])
                continue;
            if (a[ny][nx] == 1)
            {
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
            }
            if (a[ny][nx] == 0)
            {
                q.push({ny, nx});
                zero.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
                while (zero.size())
                {
                    tie(zy, zx) = zero.front();
                    zero.pop();
                    for (int j = 0; j < 4; j++)
                    {
                        int nzy = zy + dy[j];
                        int nzx = zx + dx[j];
                        if (nzy <= 0 || nzx <= 0 || nzy > n || nzx > m)
                            continue;
                        if (visited[nzy][nzx])
                            continue;
                        if (a[nzy][nzx])
                        {
                            visited[nzy][nzx] = visited[zy][zx];
                            q.push({nzy, nzx});
                        }
                        if (a[nzy][nzx] == 0)
                        {
                            visited[nzy][nzx] = visited[zy][zx];
                            zero.push({nzy, nzx});
                            q.push({nzy, nzx});
                        }
                    }
                }
            }
        }
    }
    if (visited[y2][x2] == 0)
    {
        for (int i = 0; i < 4; i++)
        {
            int ny = y2 + dy[i];
            int nx = x2 + dx[i];
            if (ny <= 0 || nx <= 0 || ny > n || nx > m)
                continue;
            res = min(res, visited[ny][nx]);
        }
    }
    else
        res = visited[y2][x2] - 1;
    cout << res << "\n";
}
