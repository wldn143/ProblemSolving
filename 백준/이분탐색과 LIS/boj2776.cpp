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
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; i++)
            cin >> b[i];
        sort(a.begin(), a.end());
        for (int i = 0; i < m; i++)
        {
            int hi = n - 1, lo = 0, flag = 0;
            while (lo <= hi)
            {
                int mid = (hi + lo) / 2;
                if (a[mid] == b[i])
                {
                    flag = 1;
                    break;
                }
                if (a[mid] < b[i])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            cout << flag << "\n";
        }
    }
    return 0;
}
