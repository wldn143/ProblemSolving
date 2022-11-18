#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
long long sum, res;
int main()
{
    cin >> n >> m;
    vector<int> v(n);
    int lo = 1, hi = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        hi = max(hi, v[i]);
        sum += v[i];
    }

    while (lo <= hi)
    {
        long long mid = (lo + hi) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += (v[i] / mid);
        }
        if (cnt < m)
            hi = mid - 1;
        else
        {
            lo = mid + 1;
            res = mid;
        }
    }
    cout << sum - (res * m) << "\n";

    return 0;
}
