#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100001][3], dp_max[2][3], dp_min[2][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
    {
        dp_max[1][0] = max(dp_max[0][0], dp_max[0][1]) + a[i][0];
        dp_max[1][1] = max(max(dp_max[0][0], dp_max[0][1]), dp_max[0][2]) + a[i][1];
        dp_max[1][2] = max(dp_max[0][1], dp_max[0][2]) + a[i][2];

        dp_min[1][0] = min(dp_min[0][0], dp_min[0][1]) + a[i][0];
        dp_min[1][1] = min(min(dp_min[0][0], dp_min[0][1]), dp_min[0][2]) + a[i][1];
        dp_min[1][2] = min(dp_min[0][1], dp_min[0][2]) + a[i][2];

        for (int j = 0; j < 3; j++)
        {
            dp_max[0][j] = dp_max[1][j];
            dp_min[0][j] = dp_min[1][j];
        }
    }
    cout << max(max(dp_max[1][0], dp_max[1][1]), dp_max[1][2]) << " ";
    cout << min(min(dp_min[1][0], dp_min[1][1]), dp_min[1][2]) << "\n";
}