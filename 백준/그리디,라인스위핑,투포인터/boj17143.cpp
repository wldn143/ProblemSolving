#include <iostream>
#include <algorithm>
using namespace std;
struct Shark
{
    int x, y, s, z, dir, death;
} a[10001];
int _map[101][101], R, C, M, res, temp[101][101];
int dx[] = {0, 0, 0, 1, -1}, dy[] = {0, -1, 1, 0, 0};
int main()
{
    cin >> R >> C >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> a[i].y >> a[i].x >> a[i].s >> a[i].dir >> a[i].z;
        a[i].y -= 1;
        a[i].x -= 1;
        _map[a[i].y][a[i].x] = i;
    }
    for (int t = 0; t < C; t++) // x
    {
        for (int i = 0; i < R; i++) // y
        {
            if (_map[i][t])
            {
                a[_map[i][t]].death = 1;
                res += a[_map[i][t]].z;
                _map[i][t] = 0;
                break;
            }
        }
        fill(&temp[0][0], &temp[0][0] + 101 * 101, 0);
        for (int i = 1; i <= M; i++)
        {
            if (a[i].death)
                continue;
            int _y = a[i].y;
            int _x = a[i].x;
            int s = a[i].s;
            int d = a[i].dir;
            int ny, nx;
            while (1)
            {
                ny = _y + s * dy[d];
                nx = _x + s * dx[d];
                if (ny >= 0 && nx >= 0 && ny < R && nx < C)
                    break;
                else if (d == 1 && ny < 0)
                    s -= _y, _y = 0, d = 2;
                else if (d == 2 && ny >= R)
                    s -= R - 1 - _y, _y = R - 1, d = 1;
                else if (d == 3 && nx >= C)
                    s -= C - 1 - _x, _x = C - 1, d = 4;
                else if (d == 4 && nx < 0)
                    s -= _x, _x = 0, d = 3;
            }
            if (temp[ny][nx])
            {
                if (a[temp[ny][nx]].z < a[i].z)
                {
                    a[temp[ny][nx]].death = 1;
                    temp[ny][nx] = i;
                }
                else
                    a[i].death = 1;
            }
            else
                temp[ny][nx] = i;
            a[i].x = nx, a[i].y = ny, a[i].dir = d;
        }
        for (int y = 0; y < R; y++)
        {
            for (int x = 0; x < C; x++)
                _map[y][x] = temp[y][x];
        }
    }

    cout << res << "\n";
    return 0;
}
