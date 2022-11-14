#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, t, x, d, k, a, res, visited[51][51], dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
vector<int> v[51];
float cnt, tot;

void go(int y, int x, int c)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (x == 0 && nx == -1)
            nx = m - 1;
        if (x == m - 1 && nx == m)
            nx = 0;
        if (ny < 1 || ny > n || nx < 0 || nx >= m || visited[ny][nx])
            continue;
        if (v[ny][nx] == c)
        {
            v[y][x] = 0;
            v[ny][nx] = 0;
            visited[ny][nx] = 1;
            cnt++;
            go(ny, nx, c);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a;
            v[i].push_back(a);
        }
    }
    for (int p = 0; p < t; p++)
    {
        cin >> x >> d >> k;
        for (int i = 1; i <= n; i++)
        {
            if (i % x == 0)
            {
                if (d == 0)
                {
                    for (int j = 0; j < k; j++)
                        rotate(v[i].begin(), v[i].begin() + (m - 1), v[i].end());
                }
                else
                    for (int j = 0; j < k; j++)
                        rotate(v[i].begin(), v[i].begin() + 1, v[i].end());
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] && !visited[i][j])
                {
                    visited[i][j] = 1;
                    go(i, j, v[i][j]);
                }
            }
        }

        if (cnt == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (v[i][j])
                    {
                        tot += v[i][j];
                        cnt++;
                    }
                }
            }
            tot /= cnt;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (v[i][j])
                    {
                        if (v[i][j] > tot)
                            v[i][j] -= 1;
                        else if (v[i][j] < tot)
                            v[i][j] += 1;
                    }
                }
            }
        }
        cnt = 0, tot = 0;
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
            res += v[i][j];
    }
    cout << res << "\n";
}
