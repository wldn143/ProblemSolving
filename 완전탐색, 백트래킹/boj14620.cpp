#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int n, ret = 987654321;
int a[10][10], v[10][10];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};
int setflower(int y, int x)
{
    int cost = a[y][x];
    v[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        v[ny][nx] = 1;
        cost += a[ny][nx];
    }
    return cost;
}
void eraseflower(int y, int x)
{
    v[y][x] = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        v[ny][nx] = 0;
    }
}
int check(int y, int x)
{
    if (v[y][x])
        return 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || v[ny][nx])
            return 0;
    }
    return 1;
}

void flower(int cnt, int hap)
{
    if (cnt == 3)
    {
        ret = min(ret, hap);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (check(i, j))
            {
                flower(cnt + 1, hap + setflower(i, j));
                eraseflower(i, j);
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    flower(0, 0);
    cout << ret << "\n";
}
