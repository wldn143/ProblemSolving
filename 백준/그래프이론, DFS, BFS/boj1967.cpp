#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, result, end_point;
vector<pair<int, int>> connect[10001];
int visited[10001];

void dfs(int node, int weight)
{
    visited[node] = 1;
    if (weight > result)
    {
        result = weight;
        end_point = node;
    }
    for (auto a : connect[node])
    {
        int tmp = a.first;
        if (!visited[tmp])
        {
            dfs(tmp, weight + a.second);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int p, c, w;
        cin >> p >> c >> w;
        connect[p].push_back({c, w});
        connect[c].push_back({p, w});
    }
    dfs(1, 0);
    fill(visited, visited + 10001, 0);
    dfs(end_point, 0);

    cout << result;
}
