#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stdio.h>
using namespace std;
int n, l, r;
int a[51][51];
int visited[51][51];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};
int tmp, res;
vector<pair<int, int>> v;
void open(int y, int x, vector<pair<int, int>> &v)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n)
            continue;
        if (visited[ny][nx])
            continue;
        if (abs(a[y][x] - a[ny][nx]) >= l && abs(a[y][x] - a[ny][nx]) <= r)
        {
            visited[y][x] = 1;
            visited[ny][nx] = 1;
            v.push_back({ny, nx});
            tmp += a[ny][nx];
            open(ny, nx, v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    while (1)
    {
        bool flag = 0;
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] == 0)
                {
                    v.clear();
                    v.push_back({i, j});
                    tmp = a[i][j];
                    open(i, j, v);
                    if (v.size() == 1)
                        continue;
                    for (pair<int, int> b : v)
                    {
                        a[b.first][b.second] = tmp / v.size();
                        flag = 1;
                    }
                }
            }

            if (!flag)
                break;
            res++;
        }
        cout << res << "\n";
    }
}