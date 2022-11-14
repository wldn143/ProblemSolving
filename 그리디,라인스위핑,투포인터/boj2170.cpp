#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, s, e, res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());
    s = v[0].first, e = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (e < v[i].first)
        {
            res += (e - s);
            s = v[i].first, e = v[i].second;
        }
        else if (e >= v[i].first && e <= v[i].second)
            e = v[i].second;
    }
    res += (e - s);
    cout << res << "\n";
}
