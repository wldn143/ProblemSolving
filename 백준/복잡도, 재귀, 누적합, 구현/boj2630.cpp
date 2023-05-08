#include <iostream>
#include <algorithm>
using namespace std;
int n, map[128][128], result[2];

void check(int y, int x, int r)
{
    int start = map[y][x];

    for (int i = y; i < y + r; i++)
    {
        for (int j = x; j < x + r; j++)
        {
            if (map[i][j] != start)
            {
                check(y, x, r / 2);
                check(y, x + r / 2, r / 2);
                check(y + r / 2, x, r / 2);
                check(y + r / 2, x + r / 2, r / 2);
                return;
            }
        }
    }

    result[start]++;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    check(0, 0, n);

    cout << result[0] << " " << result[1] << "\n";
}