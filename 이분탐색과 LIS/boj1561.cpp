#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[10001];
long long res;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    if (n <= m)
    {
        cout << n << "\n";
        return 0;
    }
    long long hi = 60000000004, lo = 0;
    while (lo <= hi)
    {
        long long mid = (lo + hi) / 2;
        long long cnt = m;
        for (int i = 0; i < m; i++)
        {
            cnt += mid / a[i];
        }
        if (cnt >= n)
        {
            hi = mid - 1;
            res = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    long long tmp = m;
    for (int i = 0; i < m; i++)
        tmp += ((res - 1) / a[i]);
    for (int i = 0; i < m; i++)
    {
        if (res % a[i] == 0)
            tmp++;
        if (tmp == n)
        {
            cout << i + 1 << "\n";
            break;
        }
    }

    return 0;
}
