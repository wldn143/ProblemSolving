#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
using namespace std;
int n, m;
queue<pair<int, int>> que;
int a[104][104];
int visited[104][104];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int q, p;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }

    visited[0][0] = 1;
    que.push({0, 0});
    while (que.size())
    {
        tie(q, p) = que.front();
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = q + dy[i];
            int nx = p + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 0)
                continue;
            if (visited[ny][nx] == 0)
            {
                visited[ny][nx] = 1;
                a[ny][nx] = a[q][p] + 1;
                que.push({ny, nx});
            }
        }
    }
    cout << a[n - 1][m - 1] << "\n";
}