#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, k, r, c, s, st, d, nxt, y, x, tmp, cnt, a[51][51], t[51][51], res = 987654321;
vector<int> v, rot[7];
pair<int, int> state[4];

void go(int idx)
{
    r = rot[idx][0];
    c = rot[idx][1];
    s = rot[idx][2];
    d = (r + s) - (r - s) + 1;
    y = r - s, x = c - s;
    while (d > 1)
    {
        int ny = y, nx = x;
        st = 0, nxt = -1, cnt = d;
        for (int i = 1; i <= 4 * (d - 1); i++)
        {
            tmp = t[ny][nx];
            t[ny][nx] = nxt;
            nxt = tmp;
            cnt--;
            if (cnt == 0)
            {
                cnt = d - 1;
                st++;
            }
            ny += state[st].first;
            nx += state[st].second;
        }
        t[y][x] = nxt;
        d -= 2;
        y++, x++;
    }
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> r >> c >> s;
        rot[i].push_back(r);
        rot[i].push_back(c);
        rot[i].push_back(s);
        v.push_back(i);
    }
    state[0] = {0, 1};
    state[1] = {1, 0};
    state[2] = {0, -1};
    state[3] = {-1, 0};
    do
    {
        copy(&a[0][0], &a[0][0] + 51 * 51, &t[0][0]);
        for (int i = 0; i < v.size(); i++)
            go(v[i]);
        for (int i = 1; i <= n; i++)
        {
            int hop = 0;
            for (int j = 1; j <= m; j++)
                hop += t[i][j];
            res = min(res, hop);
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << res << "\n";
}
