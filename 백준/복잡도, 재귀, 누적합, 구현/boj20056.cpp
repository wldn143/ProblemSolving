#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct FIREBALL
{
    int y, x, Massive, Speed, Dir;
};
vector<FIREBALL> map[51][51];
vector<FIREBALL> fireball;
int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int n, m, k, ret;
int T_dir[] = {0, 2, 4, 6};
int F_dir[] = {1, 3, 5, 7};

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        map[r][c].push_back({r, c, m, s, d});
        fireball.push_back({r, c, m, s, d});
    }

    while (k--)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                map[i][j].clear();

        for (int i = 0; i < fireball.size(); i++)
        {
            int x = fireball[i].x;
            int y = fireball[i].y;
            int Massive = fireball[i].Massive;
            int Speed = fireball[i].Speed;
            int Dir = fireball[i].Dir;

            int Move = Speed % n;
            int nx = x + dir[Dir][1] * Move;
            int ny = y + dir[Dir][0] * Move;

            if (nx > n)
                nx -= n;
            if (ny > n)
                ny -= n;
            if (nx < 1)
                nx += n;
            if (ny < 1)
                ny += n;

            map[ny][nx].push_back({ny, nx, Massive, Speed, Dir});
            fireball[i].y = ny;
            fireball[i].x = nx;
        }

        vector<FIREBALL> tmp;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (map[i][j].size() == 0)
                    continue;

                if (map[i][j].size() == 1)
                {
                    tmp.push_back(map[i][j][0]);
                    continue;
                }

                int M_sum = 0;
                int S_sum = 0;
                bool odd = true, even = true;

                // map[i][j]에 있는 파이어볼이 2개 이상
                for (int k = 0; k < map[i][j].size(); k++)
                {
                    M_sum += map[i][j][k].Massive;
                    S_sum += map[i][j][k].Speed;

                    if (map[i][j][k].Dir % 2)
                        even = false;
                    else
                        odd = false;
                }
                int M_div = M_sum / 5;
                int S_div = S_sum / map[i][j].size();
                if (!M_div)
                    continue;
                if (even || odd)
                    for (int k = 0; k < 4; k++)
                        tmp.push_back({i, j, M_div, S_div, T_dir[k]});
                else
                    for (int k = 0; k < 4; k++)
                        tmp.push_back({i, j, M_div, S_div, F_dir[k]});
            }
        }
        fireball = tmp;
    }

    for (int i = 0; i < fireball.size(); i++)
        ret += fireball[i].Massive;

    cout << ret;
}
