#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m, a, b;
vector<int> v[32001];
int degree[32001];
queue<int> q;
vector<int> ret;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        degree[b]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (degree[i] == 0)
            q.push(i);
    }

    while (q.size())
    {
        int f = q.front();
        for (int i = 0; i < v[f].size(); i++)
        {
            degree[v[f][i]]--;
            if (degree[v[f][i]] == 0)
                q.push(v[f][i]);
        }
        ret.push_back(f);
        q.pop();
    }
    for (int a : ret)
        cout << a << " ";
}
