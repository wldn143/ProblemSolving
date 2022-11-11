#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int n, x, y, d, g, res, a[104][104], visited[104][104];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1}, dir[4] = {1, 2, 3, 0};
vector<int> v;
void go(int x, int y, int d, int g)
{
    v.push_back(d);
    a[x][y] = 1;
    x += dx[d], y += dy[d];
    d = dir[d];
    v.push_back(d);
    a[x][y] = 1;
    if (g > 0)
    {
        x += dx[d], y += dy[d];
        a[x][y] = 1;
    }
    while (v.size() < pow(2, g))
    {
        for (int i = v.size() - 1; i >= 0; i--)
        {
            x += dx[dir[v[i]]], y += dy[dir[v[i]]];
            a[x][y] = 1;
            v.push_back(dir[v[i]]);
        }
    }
    v.clear();
}

void rec(int x, int y)
{
    if (x + 1 > 100 || y + 1 > 100)
        return;
    if (a[x][y + 1] && a[x + 1][y] && a[x + 1][y + 1])
    {
        res++;
        visited[x][y] = 1;
    }
    return;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> d >> g;
        go(x, y, d, g);
    }
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            if (a[i][j] && !visited[i][j])
                rec(i, j);
        }
    }
    cout << res << "\n";
}
