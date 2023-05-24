#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, u, v, tmp, cnt;
int ladder[101];
int visited[101];
queue<int> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n + m; i++)
    {
        cin >> u >> v;
        ladder[u] = v;
    }

    q.push(1);

    while (q.size())
    {
        int f = q.front();
        int cnt = visited[f];
        for (int i = 1; i <= 6; i++)
        {
            int cur = f + i;
            if (cur > 100)
                continue;
            if (ladder[cur])
                cur = ladder[cur];

            if (visited[cur] && visited[cur] <= cnt + 1)
                continue;

            visited[cur] = cnt + 1;
            q.push(cur);
        }
        q.pop();
    }
    cout << visited[100];
}