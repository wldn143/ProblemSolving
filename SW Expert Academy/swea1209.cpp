#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int T, n, k, a[101][101];
int main()
{
    for (int t = 1; t <= 10; t++)
    {
        cin >> n;
        vector<int> r(101), c(101);
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                cin >> a[i][j];
                r[i] += a[i][j];
                c[j] += a[i][j];
            }
        }
        int y1 = 0, x1 = 0, y2 = 0, x2 = 99, p = 0, q = 0, res = 0;

        for (int i = 0; i < 100; i++)
        {
            p += a[y1][x1];
            q += a[y2][x2];
            y1++, x1++;
            y2++, x2--;
        }
        sort(r.begin(), r.end(), greater<>());
        sort(c.begin(), c.end(), greater<>());
        int mx1 = max(c[0], r[0]);
        int mx2 = max(p, q);
        res = max(mx1, mx2);
        cout << "#" << t << " " << res << "\n";
    }
    return 0;
}