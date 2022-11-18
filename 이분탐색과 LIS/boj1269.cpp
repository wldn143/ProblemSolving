#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t, n, m, res;
int main()
{
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        int hi = m - 1, lo = 0;
        while (lo <= hi)
        {
            int mid = (hi + lo) / 2;
            if (a[i] == b[mid])
            {
                res++;
                break;
            }
            if (a[i] > b[mid])
                lo = mid + 1;
            else if (a[i] < b[mid])
                hi = mid - 1;
        }
    }
    cout << a.size() + b.size() - (res * 2) << "\n";
    return 0;
}
