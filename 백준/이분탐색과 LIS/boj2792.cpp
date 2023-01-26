#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int main()
{
    cin >> n >> m;
    vector<long long> v(m);
    long long mid, ret, left = 1, right = 0, sum;
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
        right = max(v[i], right);
    }

    while (left <= right)
    {
        mid = (left + right) / 2;
        sum = 0;
        for (int i = 0; i < m; i++)
        {
            sum += v[i] / mid;
            if (v[i] % mid)
                sum++;
        }
        if (sum <= n)
        {
            right = mid - 1;
            ret = mid;
        }
        else
            left = mid + 1;
    }
    cout << ret << "\n";

    return 0;
}
