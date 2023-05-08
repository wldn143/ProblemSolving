#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, u, v, cnt, result, connect[1001][1001], visited[1001];
queue<int> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        connect[u][v] = 1;
        connect[v][u] = 1;
    }

    cnt = n;

    while (cnt > 0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
                continue;

            q.push(i);
            cnt--;

            while (q.size())
            {
                int f = q.front();

                for (int i = 1; i <= n; i++)
                {
                    if (connect[f][i] && !visited[i])
                    {
                        visited[i] = 1;
                        q.push(i);
                        cnt--;
                    }
                }
                q.pop();
            }
            result++;
        }
    }

    cout << result;
}