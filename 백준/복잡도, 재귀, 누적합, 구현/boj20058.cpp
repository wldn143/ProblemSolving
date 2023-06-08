#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int n, m, sum, mx, cnt;
int map[65][65];
int visited[65][65];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];

        if (ny < 0 || nx < 0 || ny >= pow(2, n) || nx >= pow(2, n) || visited[ny][nx] || !map[ny][nx])
            continue;
        cnt++;
        dfs(ny, nx);
    }
    return;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    cin >> n >> m;
    int size = pow(2, n);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> map[i][j];

    while (m--)
    {
        int L;
        cin >> L;
        if (L)
            for (int i = 0; i < size; i += pow(2, L))
            {
                for (int j = 0; j < size; j += pow(2, L))
                {
                    int s_y = i, s_x = j;
                    int y, x;
                    for (int l = pow(2, L); l > 0; l -= 2)
                    {
                        int repeat = l - 1;
                        while (repeat--)
                        {
                            int y = s_y, x = s_x;
                            int prv = map[y][x];
                            for (int k = 0; k < 4; k++)
                            {
                                for (int p = 1; p < l; p++)
                                {
                                    int nxt = map[y + dir[k][0]][x + dir[k][1]];
                                    y += dir[k][0];
                                    x += dir[k][1];
                                    map[y][x] = prv;
                                    prv = nxt;
                                }
                            }
                        }
                        s_y++, s_x++;
                        y = s_y, x = s_x;
                    }
                }
            }

        vector<pair<int, int>> melt;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (map[i][j])
                {
                    int cnt = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int ny = i + dir[k][0];
                        int nx = j + dir[k][1];

                        if (ny < 0 || nx < 0 || ny >= size || nx >= size || !map[ny][nx])
                            continue;

                        cnt++;
                    }
                    if (cnt < 3)
                        melt.push_back({i, j});
                }
            }
        }

        for (auto i : melt)
            map[i.first][i.second]--;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sum += map[i][j];
            if (map[i][j] && !visited[i][j])
            {
                cnt = 1;
                dfs(i, j);
                mx = max(mx, cnt);
            }
        }
    }

    cout << sum << "\n"
         << mx;
}
