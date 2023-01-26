#include <iostream>
#include <algorithm>
using namespace std;
int n, m, t, a[51][51], tmp[51][51], visited[51][51], gx1, gy1, gx2, gy2, cnt, res;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
void move(int y, int x, int c)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 1 || nx < 1 || ny > n || nx > m || a[ny][nx] == -1)
            continue;
        c++;
        tmp[ny][nx] += (a[y][x] / 5);
        if (!visited[ny][nx])
            move(ny, nx, 0);
    }

    tmp[y][x] += (a[y][x] - (a[y][x] / 5) * c);
    return;
}

void wind(int y, int x, int mod, int d)
{
    int ny, nx;
    if (mod == 1)
    {
        ny = y;
        nx = x + 1;
        if (nx == m)
        {
            if (d == 0)
                wind(ny, nx, 2, d);
            else
                wind(ny, nx, 4, d);
        }
        else
            wind(ny, nx, 1, d);
    }

    if (mod == 2)
    {
        ny = y - 1;
        nx = x;
        if (ny == 1)
            wind(ny, nx, 3, d);
        else if (ny == gy2)
            return;

        else
            wind(ny, nx, 2, d);
    }
    if (mod == 3)
    {
        ny = y;
        nx = x - 1;
        if (nx == gx1)
        {
            if (d == 0)
                wind(ny, nx, 4, d);
            else
                wind(ny, nx, 2, d);
        }
        else
            wind(ny, nx, 3, d);
    }
    if (mod == 4)
    {
        ny = y + 1;
        nx = x;
        if (ny == gy1)
            return;

        else if (ny == n)
            wind(ny, nx, 3, d);

        else
            wind(ny, nx, 4, d);
    }
    tmp[ny][nx] = tmp[y][x];
    if (tmp[ny][nx] == -1)
        tmp[ny][nx] = 0;
}

int main()
{
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == -1)
            {
                if (!cnt)
                {
                    gx1 = j;
                    gy1 = i;
                }
                else
                {
                    gx2 = j;
                    gy2 = i;
                }
                cnt++;
            }
        }
    }

    while (t--)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == -1)
                    tmp[i][j] = -1;
                else if (a[i][j] != 0 && !visited[i][j])
                    move(i, j, 0);
            }
        }

        wind(gy1, gx1, 1, 0);
        wind(gy2, gx2, 1, 1);
        if (t == 0)
            break;
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        copy(&tmp[0][0], &tmp[0][0] + 51 * 51, &a[0][0]);
        fill(&tmp[0][0], &tmp[0][0] + 51 * 51, 0);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            res += tmp[i][j];
        }
    }
    cout << res + 2 << "\n";
}
