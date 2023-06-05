#include <iostream>
#include <algorithm>
using namespace std;
int n, m, map[51][51];
int y, x, d, cnt;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 북 동 남 서
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    cin >> y >> x >> d;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    while (1)
    {
        int flag = 0;

        if (map[y][x] == 0)
        {
            map[y][x] = -1;
            cnt++;
        }

        else
        {
            for (int i = 0; i < 4; i++)
            {
                int dy = y + dir[i][0];
                int dx = x + dir[i][1];
                if (dy < 0 || dx < 0 || dy >= n || dx >= m)
                    continue;
                if (map[dy][dx] == 0)
                {
                    flag = 1;
                    d--;
                    if (d < 0)
                        d = 3;
                    break;
                }
            }

            if (flag)
            {
                if (map[y + dir[d][0]][x + dir[d][1]] == 0)
                {
                    y += dir[d][0];
                    x += dir[d][1];
                }
            }
            else
            {
                int dy = y + dir[d][0] * -1;
                int dx = x + dir[d][1] * -1;
                if (map[dy][dx] == 1)
                    break;
                y = dy;
                x = dx;
            }
        }
    }
    cout << cnt;
}
