#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, m, ly, lx, y, x, flag, p, q;
char c;
char a[1501][1501];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
int m_visited[1501][1501];
int l_visited[1501][1501];
queue<pair<int, int>> map;
queue<pair<int, int>> buf;
queue<pair<int, int>> em;
queue<pair<int, int>> res;
queue<pair<int, int>> buf2;
void melt()
{
    while (map.size() || buf.size())
    {
        tie(y, x) = map.front();
        map.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (m_visited[ny][nx])
                continue;
            if (a[ny][nx] == '.')
            {
                m_visited[ny][nx] = m_visited[y][x];
                map.push({ny, nx});
            }
            else if (a[ny][nx] == 'X')
            {
                m_visited[ny][nx] = m_visited[y][x] + 1;
                a[ny][nx] = '.';
                buf.push({ny, nx});
            }
        }

        if (map.size() == 0)
        {
            map = buf;
            buf = em;
            while (res.size())
            {
                tie(p, q) = res.front();
                res.pop();
                for (int i = 0; i < 4; i++)
                {
                    int yy = dy[i] + p;
                    int xx = dx[i] + q;
                    if (yy < 0 || xx < 0 || yy >= n || xx >= m)
                        continue;
                    if (l_visited[yy][xx])
                        continue;
                    if (a[yy][xx] == 'L')
                    {
                        flag = l_visited[p][q];
                        return;
                    }
                    if (a[yy][xx] == '.')
                    {
                        l_visited[yy][xx] = l_visited[p][q];
                        res.push({yy, xx});
                    }
                    if (a[yy][xx] == 'X')
                    {
                        l_visited[yy][xx] = l_visited[p][q] + 1;
                        buf2.push({yy, xx});
                    }
                }
            }
            res = buf2;
            buf2 = em;
        }
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
            if (a[i][j] == 'L')
            {
                ly = i;
                lx = j;
            }
            if (a[i][j] == '.' || a[i][j] == 'L')
            {
                m_visited[i][j] = 1;
                map.push({i, j});
            }
        }
    }
    res.push({ly, lx});
    l_visited[ly][lx] = 1;
    melt();

    cout << flag << "\n";
}
