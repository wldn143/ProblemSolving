#include <iostream>
#include <algorithm>
using namespace std;
int n, k, a[101][101], cnt;
char c[8][8];
void check_r(int y, int x)
{
    if (x + n > 8)
        return;
    for (int i = 0; i < n / 2; i++)
        if (c[y][x + i] != c[y][x + n - (i + 1)])
            return;
    cnt++;
}
void check_l(int y, int x)
{
    if (y + n > 8)
        return;
    for (int i = 0; i < n / 2; i++)
        if (c[y + i][x] != c[y + n - (i + 1)][x])
            return;
    cnt++;
}
int main()
{
    for (int t = 1; t <= 10; t++)
    {
        cin >> n;
        cnt = 0;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                scanf("%1s", &c[i][j]);
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                check_r(i, j);
                check_l(j, i);
            }
        }
        cout << "#" << t << " " << cnt << "\n";
    }
    return 0;
}