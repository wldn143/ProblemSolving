#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, x, y;
vector<int> connect[100001];
int visited[100001];
queue<int> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        connect[x].push_back(y);
        connect[y].push_back(x);
    }
    q.push(1);
    visited[1] = 1;
    while (q.size())
    {
        int f = q.front();
        for (int a : connect[f])
        {
            if (visited[a])
                continue;
            q.push(a);
            visited[a] = f;
        }
        q.pop();
    }

    for (int i = 2; i <= n; i++)
        cout << visited[i] << "\n";
}
