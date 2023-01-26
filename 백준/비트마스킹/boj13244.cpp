#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
int t, n, m, a, b, cnt, c[1001][1001], visited[1001]; //메모리초과 시 배열 벡터로
void dfs(int node)
{
    visited[node] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (c[node][i] && !visited[i])
            dfs(i);
    }
}
int main()
{
    cin >> t;
    while (t--)
    {
        fill(visited, visited + 1001, 0);
        fill(&c[0][0], &c[0][0] + 1001 * 1001, 0);
        cnt = 0;
        cin >> n >> m; //엣지 수
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            c[a][b] = 1, c[b][a] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                dfs(i);
                cnt++;
            }
        }
        if (m == n - 1 && cnt == 1)
            cout << "tree"
                 << "\n";
        else
            cout << "graph"
                 << "\n";
    }
}
