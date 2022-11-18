#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t, n, m;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<int> a(n), b(m);
        int res = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++)
        {
            auto pos = lower_bound(b.begin(), b.end(), a[i]);
            res += (int)(pos - b.begin());
        }
        cout << res << "\n";
    }
    return 0;
}
