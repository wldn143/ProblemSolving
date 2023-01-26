#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
int n, m;
int mx;
int res[10001];
int visited[10001];
vector<int> map[10001];

int dfs(int x)
{
    visited[x] = 1;
    int cnt = 1;
    for (int i : map[x])
    {
        if (visited[i])
            continue;
        cnt += dfs(i);
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
        res[i] = dfs(i);
        mx = max(res[i], mx);
    }

    for (int i = 1; i <= n; i++)
    {
        if (res[i] == mx)
            cout << i << " ";
    }
}
