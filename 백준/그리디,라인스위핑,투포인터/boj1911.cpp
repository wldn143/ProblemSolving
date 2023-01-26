#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, l, ret, idx, cnt;
int main()
{
    cin >> n >> l;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (v[i].second <= idx)
            continue;
        if (idx < v[i].first)
        {
            cnt = (v[i].second - v[i].first) / l;
            if ((v[i].second - v[i].first) % l)
                cnt += 1;
            idx = v[i].first + cnt * l;
        }
        else
        {
            cnt = ((v[i].second - idx) / l);
            if ((v[i].second - idx) % l)
                cnt += 1;
            idx = idx + cnt * l;
        }
        ret += cnt;
    }
    cout << ret << "\n";
}
