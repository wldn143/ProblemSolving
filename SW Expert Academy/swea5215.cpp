#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int T, n, l;
int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n >> l;
        pair<int, int> v[n];
        int mx = 0;
        for (int i = 0; i < n; i++)
            cin >> v[i].first >> v[i].second;
        for (int i = 1; i < (1 << n); i++)
        {
            int fav = 0, cal = 0;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    fav += v[j].first;
                    cal += v[j].second;
                }
            }
            if (cal <= l)
                mx = max(mx, fav);
        }
        cout << "#" << t << " " << mx << "\n";
    }
    return 0;
}