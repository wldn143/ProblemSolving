#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, y, x;
int a[51][51];
int visited[51][51];
string s;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int mx, res;

int bfs(int sy, int sx)
{
    queue<pair<int, int>> q;
    q.push({sy, sx});
    while (!q.empty())
    {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (visited[ny][nx] || a[ny][nx] == 0)
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            mx = max(mx, visited[ny][nx]);
            q.push({ny, nx});
        }
    }
    return mx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == 'L')
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }

    // visited 초기화 필수
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 1)
            {
                fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
                visited[i][j] = 1;
                int o = bfs(i, j);
                res = max(res, o);
            }
        }
    }
    cout << res - 1 << "\n";
}
