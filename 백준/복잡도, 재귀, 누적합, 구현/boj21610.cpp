#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, ret;
int map[51][51];
int dir[9][2] = {{0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
int cross[4][2] = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
bool ex[51][51];
struct cloud
{
    int y;
    int x;
};
vector<cloud> c;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> map[i][j];

    c.push_back({n - 1, 1});
    c.push_back({n - 1, 2});
    c.push_back({n, 1});
    c.push_back({n, 2});

    int d, s;

    for (int t = 0; t < m; t++)
    {
        cin >> d >> s;

        vector<cloud> tmp;

        for (int i = 0; i < c.size(); i++)
        {
            int y = c[i].y;
            int x = c[i].x;

            int ny = y + dir[d][0] * (s % n);
            int nx = x + dir[d][1] * (s % n);

            if (ny > n)
                ny -= n;
            if (nx > n)
                nx -= n;
            if (ny < 1)
                ny += n;
            if (nx < 1)
                nx += n;

            tmp.push_back({ny, nx});

            map[ny][nx]++;
            ex[ny][nx] = 1;
        }

        for (int i = 0; i < tmp.size(); i++)
        {
            int y = tmp[i].y;
            int x = tmp[i].x;

            for (int j = 0; j < 4; j++)
            {
                int ny = y + cross[j][0];
                int nx = x + cross[j][1];

                if (ny < 1 || nx < 1 || ny > n || nx > n)
                    continue;

                if (map[ny][nx])
                    map[y][x]++;
            }
        }

        c.clear();

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (map[i][j] >= 2 && ex[i][j] == 0)
                {
                    map[i][j] -= 2;
                    c.push_back({i, j});
                }
                ex[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ret += map[i][j];

    cout << ret;
}
