#include <iostream>
#include <algorithm>
using namespace std;
int n, cnt, a[17][17], dir[3][2] = {{0, 1}, {1, 0}, {1, 1}};
void go(int y, int x, int cur)
{
    if (y >= n || x >= n || a[y][x] == 1)
        return;
    if (cur == 2)
    {
        if (a[y - 1][x] == 1 || a[y][x - 1] == 1)
            return;
    }
    if (y == n - 1 && x == n - 1)
    {
        cnt++;
        return;
    }
    if (cur == 0)
    {
        go(y + dir[0][0], x + dir[0][1], 0);
        go(y + dir[2][0], x + dir[2][1], 2);
    }
    else if (cur == 1)
    {
        go(y + dir[1][0], x + dir[1][1], 1);
        go(y + dir[2][0], x + dir[2][1], 2);
    }
    else if (cur == 2)
    {
        go(y + dir[0][0], x + dir[0][1], 0);
        go(y + dir[1][0], x + dir[1][1], 1);
        go(y + dir[2][0], x + dir[2][1], 2);
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    go(0, 1, 0);
    cout << cnt << "\n";
}
