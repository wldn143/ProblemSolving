#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
int n, m, y, x, bit, res, mx = -1, a[4][4], b[4][4], visited[4][4];
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
string s;
void yd(int y, int x)
{
    s += to_string(a[y][x]);
    for (int i = 0; i < 4; i++)
    {
        int ny = dy[i] + y;
        if (ny < 0 || ny >= n || visited[ny][x] || !b[ny][x])
            continue;
        visited[ny][x] = 1;
        yd(ny, x);
    }
}
void xd(int y, int x)
{
    s += to_string(a[y][x]);
    for (int i = 0; i < 4; i++)
    {
        int nx = dx[i] + x;
        if (nx < 0 || nx >= m || visited[y][nx] || b[y][nx])
            continue;
        visited[y][nx] = 1;
        xd(y, nx);
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }

    for (int i = 0; i < (1 << n * m); i++)
    {
        fill(&visited[0][0], &visited[0][0] + 4 * 4, 0);
        fill(&b[0][0], &b[0][0] + 4 * 4, 0);
        x = 0, y = 0, s = "", res = 0;

        for (int j = 0; j < n * m; j++)
        {
            if ((i & (1 << j)))
                bit = 1;

            else
                bit = 0;

            if (x == m - 1)
            {
                b[y][x] = bit;
                x = 0, y++;
            }
            else
            {
                b[y][x] = bit;
                x++;
            }
        }

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (!visited[j][k])
                {
                    s = "";
                    visited[j][k] = 1;
                    if (b[j][k])
                        yd(j, k);
                    else
                        xd(j, k);
                    res += stoi(s);
                }
            }
        }

        mx = max(mx, res);
    }
    cout << mx << "\n";
}
