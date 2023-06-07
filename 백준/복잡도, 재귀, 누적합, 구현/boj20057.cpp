#include <iostream>
#include <algorithm>
using namespace std;
int n, sand, dir;
int map[500][500];
int d[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
int rat[9] = {1, 1, 7, 7, 2, 2, 10, 10, 5};
int mask[4][9][2] = {{{-1, 1}, {1, 1}, {-1, 0}, {1, 0}, {-2, 0}, {2, 0}, {-1, -1}, {1, -1}, {0, -2}},
                     {{-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {0, -2}, {0, 2}, {1, -1}, {1, 1}, {2, 0}},
                     {{-1, -1}, {1, -1}, {-1, 0}, {1, 0}, {-2, 0}, {2, 0}, {-1, 1}, {1, 1}, {0, 2}},
                     {{1, 1}, {1, -1}, {0, 1}, {0, -1}, {0, -2}, {0, 2}, {-1, 1}, {-1, -1}, {-2, 0}}};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            sand += map[i][j];
        }

    int y = (n - 1) / 2;
    int x = (n - 1) / 2;

    int cnt = 1;
    int t = 2;
    int flag = 0;

    while (!flag)
    {
        t = 2;
        while (t--)
        {
            for (int i = 0; i < cnt; i++)
            {
                y += d[dir][0];
                x += d[dir][1];

                int init = map[y][x];
                int left = map[y][x];
                for (int j = 0; j < 9; j++)
                {
                    int ny = y + mask[dir][j][0];
                    int nx = x + mask[dir][j][1];

                    if (ny >= 0 && nx >= 0 && ny < n && nx < n)
                    {
                        map[ny][nx] += ((init * rat[j]) / 100);
                    }

                    left -= ((init * rat[j]) / 100);
                }

                int ny = y + d[dir][0];
                int nx = x + d[dir][1];
                if (ny >= 0 && nx >= 0 && ny < n && nx < n)
                    map[ny][nx] += left;

                map[y][x] = 0;

                if (cnt == n)
                    flag = 1;
            }

            dir++;
            if (dir == 4)
                dir = 0;
        }
        cnt++;
    }

    int remain = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            remain += map[i][j];

    cout << sand - remain;
}
