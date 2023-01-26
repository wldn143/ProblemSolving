#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[1001][1001], ret;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%1d", &a[i][j]);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 1)
                a[i][j] = min(min(a[i - 1][j], a[i][j - 1]), a[i - 1][j - 1]) + 1;
            ret = max(ret, a[i][j]);
        }
    }

    cout << ret * ret << "\n";
}