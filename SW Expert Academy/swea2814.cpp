#include <iostream>
#include <algorithm>
using namespace std;
int T, n, m, a, b, g[11][11], visited[11], mx;

void dfs(int node, int cnt)
{
    for (int i = 1; i <= n; i++)
    {
        if (g[node][i] && !visited[i])
        {
            visited[i] = 1;
            dfs(i, cnt + 1);
            visited[i] = 0;
        }
    }
    mx = max(mx, cnt);
    return;
}
int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n >> m;
        mx = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            g[a][b] = 1;
            g[b][a] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                visited[i] = 1;
                dfs(i, 1);
                visited[i] = 0;
            }
        }
        cout << "#" << t << " " << mx << "\n";
        fill(&g[0][0], &g[0][0] + 11 * 11, 0);
    }
    return 0;
}