#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, a[21][21], tmp[21][21], sel[5], d[4] = {1, 2, 3, 4}, mx, v[21];
vector<int> fw, rv, y_dir, x_dir, vv;
void hop(int dir)
{
    if (dir == 1 || dir == 3)
        y_dir = fw, x_dir = fw;
    if (dir == 2)
        y_dir = rv, x_dir = fw;
    if (dir == 4)
        y_dir = fw, x_dir = rv;

    if (dir == 1 || dir == 2)
    {
        for (int i = 0; i < x_dir.size(); i++)
        {
            int x = x_dir[i];
            int cy = -1, cx = -1;
            for (int j = 0; j < y_dir.size(); j++)
            {
                int y = y_dir[j];
                if (tmp[y][x])
                {
                    if (cy == -1)
                        cy = y, cx = x;
                    else if (tmp[cy][cx] == tmp[y][x])
                    {
                        tmp[cy][cx] *= 2;
                        tmp[y][x] = 0;
                        v[cy] = tmp[cy][cx];
                        cy = -1, cx = -1;
                    }
                    else
                        cy = y, cx = x;
                }
                v[y] = tmp[y][x];
            }
            for (int j = 0; j < n; j++)
            {
                int y = y_dir[j];
                if (v[y])
                    vv.push_back(v[y]);
            }
            int c;
            for (int j = 0; j < vv.size(); j++)
            {
                c = j;
                int y = y_dir[j];
                tmp[y][x] = vv[j];
            }
            for (int j = c + 1; j < n; j++)
            {
                int y = y_dir[j];
                tmp[y][x] = 0;
            }
            vv.clear();
            fill(&v[0], &v[0] + 21, 0);
        }
    }
    else
    {
        for (int i = 0; i < y_dir.size(); i++)
        {
            int y = y_dir[i];
            int cy = -1, cx = -1;
            for (int j = 0; j < x_dir.size(); j++)
            {
                int x = x_dir[j];
                if (tmp[y][x] != 0)
                {
                    if (cy == -1)
                        cy = y, cx = x;
                    else if (tmp[cy][cx] == tmp[y][x])
                    {
                        tmp[cy][cx] *= 2;
                        tmp[y][x] = 0;
                        v[cx] = tmp[cy][cx];
                        cy = -1, cx = -1;
                    }
                    else
                        cy = y, cx = x;
                }
                v[x] = tmp[y][x];
            }
            for (int j = 0; j < n; j++)
            {
                int x = x_dir[j];
                if (v[x])
                    vv.push_back(v[x]);
            }
            int c;
            for (int j = 0; j < vv.size(); j++)
            {
                c = j;
                int x = x_dir[j];
                tmp[y][x] = vv[j];
            }
            for (int j = c + 1; j < n; j++)
            {
                int x = x_dir[j];
                tmp[y][x] = 0;
            }
            vv.clear();
            fill(&v[0], &v[0] + 21, 0);
        }
    }
}

void combi(int idx, int cnt)
{
    if (cnt == 5)
    {
        copy(&a[0][0], &a[0][0] + 21 * 21, &tmp[0][0]);
        for (int i = 0; i < 5; i++)
            hop(sel[i]);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                mx = max(mx, tmp[i][j]);
        }
        return;
    }
    for (int i = idx; i < 4; i++)
    {
        sel[cnt] = d[i];
        combi(idx, cnt + 1);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        fw.push_back(i);
        rv.push_back(n - i - 1);
    }
    combi(0, 0);
    cout << mx << "\n";
}
