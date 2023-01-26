#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[100001], hi, lo, res;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        hi += a[i];
        lo = max(lo, a[i]);
    }
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        int cnt = 1, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum + a[i] <= mid)
                sum += a[i];
            else
            {
                cnt++;
                sum = a[i];
            }
        }
        if (cnt <= m)
        {
            hi = mid - 1;
            res = mid;
        }
        else
            lo = mid + 1;
    }
    cout << res << "\n";

    return 0;
}
