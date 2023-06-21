#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 987654321
using namespace std;
int n, m;
int connect[201][201];
int visited[201];
queue<int> q;
vector<int> v;
void bfs()
{
    while (q.size())
    {
        int f = q.front();
        visited[f] = 1;
        v.push_back(f);

        for (int i = 1; i <= n; i++)
        {
            if (connect[f][i] && connect[i][f] && !visited[i])
                q.push(i);
        }
        q.pop();
    }

    for (int i = 0; i < v.size() - 1; i++) // 0 1
    {
        for (int j = i + 1; j < v.size(); j++) // 1 2
        {
            connect[v[i]][v[j]] = 1;
            connect[v[j]][v[i]] = 1;
        }
    }
    v.clear();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int t;
            cin >> t;
            if (t)
            {
                connect[i][j] = 1;
                connect[j][i] = 1;
            }
        }
        connect[i][i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            q.push(i);
            bfs();
        }
    }

    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }

    for (int i = 1; i < m; i++)
    {
        if (!connect[v[i - 1]][v[i]])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
