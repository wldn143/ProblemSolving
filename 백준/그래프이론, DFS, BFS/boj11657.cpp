#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 9876543210
#define ll long long
using namespace std;
int n, m, a, b, c;
ll dist[501];
vector<pair<pair<int, int>, int>> edge;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b >> c;
        edge.push_back({{a, b}, c});
    }

    for (int i = 2; i <= n; i++)
        dist[i] = MAX;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < edge.size(); j++)
        {
            int from = edge[j].first.first;
            int to = edge[j].first.second;
            int cost = edge[j].second;

            if (dist[from] == MAX)
                continue;

            dist[to] = min(dist[to], dist[from] + cost);
        }
    }

    for (int j = 0; j < edge.size(); j++)
    {
        int from = edge[j].first.first;
        int to = edge[j].first.second;
        int cost = edge[j].second;

        if (dist[from] == MAX)
            continue;

        if (dist[to] > dist[from] + cost)
        {
            cout << -1;
            return 0;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (dist[i] == MAX)
            cout << -1 << "\n";
        else
            cout << dist[i] << "\n";
    }
}
