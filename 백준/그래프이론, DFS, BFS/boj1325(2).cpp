#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;
int n, m;
int mx;
int res[10001];
int visited[10001];
queue<int> q;
vector<int> map[10001];

int bfs(int x)
{
    q.push(x);
    visited[x] = 1;
    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int k : map[node])
        {
            if (visited[k])
                continue;
            visited[k] = 1;
            cnt++;
            q.push(k);
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        map[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        res[i] = bfs(i);
        mx = max(res[i], mx);
    }

    for (int i = 1; i <= n; i++)
    {
        if (res[i] == mx)
            cout << i << " ";
    }
}
