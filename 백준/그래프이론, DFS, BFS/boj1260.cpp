#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, v;
queue<int> q;
int connect[1001][1001];
int visited[1001];
int visited2[1001];

void dfs(int node)
{
    visited[node] = 1;
    cout << node << " ";
    for (int i = 1; i <= n; i++)
    {
        if (connect[node][i] || connect[i][node])
        {
            if (!visited[i])
                dfs(i);
        }
    }
}

void bfs()
{
    q.push(v);
    visited2[v] = 1;
    while (q.size())
    {
        int f = q.front();
        for (int i = 1; i <= n; i++)
        {
            if (connect[i][f] || connect[f][i])
            {
                if (!visited2[i])
                {
                    q.push(i);
                    visited2[i] = 1;
                }
            }
        }
        q.pop();
        cout << f << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> v;

    while (m--)
    {
        int i, j;
        cin >> i >> j;
        connect[i][j] = 1;
        connect[j][i] = 1;
    }

    dfs(v);
    cout << "\n";
    bfs();
}