#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll x, y, mid, res;
int main()
{
    cin >> x >> y;
    ll z = y * 100 / x;
    ll lo = 0, hi = 1e9;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if ((y + mid) * 100 / (x + mid) > z)
        {
            res = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }

    cout << (res ? res : -1) << "\n";
    return 0;
}
