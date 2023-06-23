#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#define MAX 987654321
using namespace std;
int N, R, Q, ret;
vector<int> edge[100001];
int visited[100001];
int dp[100001];
void dfs(int n, int parent)
{
    visited[n] = 1;
    for (int i = 0; i < edge[n].size(); i++)
    {
        int nxt = edge[n][i];
        if (!visited[nxt])
            dfs(nxt, n);
    }
    if (parent != -1)
        dp[parent] += dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> R >> Q;

    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    fill_n(dp, 100001, 1);
    dfs(R, -1);

    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;
        cout << dp[q] << '\n';
    }
}
