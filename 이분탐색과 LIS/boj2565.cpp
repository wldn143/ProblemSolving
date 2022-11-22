#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, lis[501], len;
int main()
{
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(lis, lis + len, v[i].second);
        if (*it == 0)
            len++;
        *it = v[i].second;
    }
    cout << n - len << "\n";
    return 0;
}