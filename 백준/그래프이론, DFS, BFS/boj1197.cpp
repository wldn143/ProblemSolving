#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 987654321
using namespace std;
int v, e, ret;
vector<pair<int, pair<int, int>>> edge;
int parent[10001];
int find_parent(int a)
{
    if (parent[a] == a)
        return a;
    else
        return parent[a] = find_parent(parent[a]);
}
void uni(int a, int b) // 최종 부모 합치기!!!
{
    a = find_parent(a);
    b = find_parent(b);
    if (a > b)
        parent[a] = b;
    else
        parent[b] = a;
}
bool is_cycle(int a, int b) // 최초 조상님만 비교하면되니께
{
    a = find_parent(a);
    b = find_parent(b);

    if (a == b)
        return 1;
    return 0;
}

int main()
{
    cin >> v >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({c, {a, b}});
    }
    sort(edge.begin(), edge.end());

    for (int i = 1; i <= v; i++)
        parent[i] = i;

    for (int i = 0; i < edge.size(); i++)
    {
        if (is_cycle(edge[i].second.first, edge[i].second.second) == 0)
        {
            uni(edge[i].second.first, edge[i].second.second);
            ret += edge[i].first;
        }
    }
    cout << ret;
}
