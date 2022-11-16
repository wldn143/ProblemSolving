#include <iostream>
#include <algorithm>
using namespace std;
int T, n, k, a[50][50], res;

int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n;
        res = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%1d", &a[i][j]);
            }

            res += a[i][n / 2];
            for (int l = 1; l <= cnt; l++)
            {
                res += a[i][(n / 2) - l];
                res += a[i][(n / 2) + l];
            }
            if (i < n / 2)
                cnt++;
            else
                cnt--;
        }
        cout << "#" << t << " " << res << "\n";
    }
    return 0;
}