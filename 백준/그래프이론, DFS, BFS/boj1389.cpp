#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, v;
queue<pair<int, int>> q;
int connect[101][101];
int visited[101], result[101], mn = 987654321, res;

void bfs(int start)
{
    q.push({start, 0});
    visited[start] = 1;

    while (q.size())
    {
        int val, cnt;
        tie(val, cnt) = q.front();

        for (int i = 1; i <= n; i++)
        {
            if (connect[i][val] || connect[val][i])
            {
                if (!visited[i])
                {
                    q.push({i, cnt + 1});
                    result[start] += cnt + 1;
                    visited[i] = 1;
                }
            }
        }
        q.pop();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    while (m--)
    {
        int i, j;
        cin >> i >> j;
        connect[i][j] = 1;
        connect[j][i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        bfs(i);
        fill(visited, visited + 101, 0);
    }
    for (int i = n; i > 0; i--)
    {
        if (result[i] <= mn)
        {
            mn = result[i];
            res = i;
        }
    }
    cout << res;
}