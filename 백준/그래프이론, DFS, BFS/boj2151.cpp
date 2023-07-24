#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;
int n, sy, sx, ey, ex, ret = INF;
string map[51];
vector<pair<int, int>> v;
queue<pair<pair<int, int>, pair<int, int>>> q;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int checked[51][51][4];
int isValid(int y, int x)
{
    return (y >= 0 && x >= 0 && y < n && x < n && map[y][x] != '*');
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> map[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == '#')
                v.push_back({i, j});
        }
    }

    sy = v[0].first;
    sx = v[0].second;
    ey = v[1].first;
    ex = v[1].second;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < 4; k++)
                checked[i][j][k] = INF;

    for (int i = 0; i < 4; i++)
    {
        q.push({{sy, sx}, {i, 0}});
        checked[sy][sx][i] = 0;
    }

    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int d = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if (y == ey && x == ex)
            ret = min(ret, cnt);

        int ny = y + dir[d][0];
        int nx = x + dir[d][1];

        if (isValid(ny, nx))
        {
            if (checked[ny][nx][d] > cnt)
            {
                q.push({{ny, nx}, {d, cnt}});
                checked[ny][nx][d] = cnt;
            }

            if (map[ny][nx] == '!')
            {
                if (d == 0 || d == 1)
                {
                    for (int j = 2; j <= 3; j++)
                    {
                        if (checked[ny][nx][j] > cnt + 1)
                        {
                            checked[ny][nx][j] = cnt + 1;
                            q.push({{ny, nx}, {j, cnt + 1}});
                        }
                    }
                }

                else if (d == 2 || d == 3)
                {
                    for (int j = 0; j <= 1; j++)
                    {
                        if (checked[ny][nx][j] > cnt + 1)
                        {
                            checked[ny][nx][j] = cnt + 1;
                            q.push({{ny, nx}, {j, cnt + 1}});
                        }
                    }
                }
            }
        }
    }
    cout << ret;
}