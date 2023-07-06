#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m, a, b;
vector<int> node[32001];
int indgree[32001];
priority_queue<int, vector<int>, greater<int>> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        node[a].push_back(b);
        indgree[b]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (indgree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int f = q.top();
        q.pop();
        cout << f << " ";
        for (int i : node[f])
        {
            if (--indgree[i] == 0)
                q.push(i);
        }
    }
}
