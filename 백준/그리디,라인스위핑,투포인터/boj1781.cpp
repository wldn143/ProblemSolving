#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, p, d, res;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> q;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d >> p; //데드라인, 컵라면 개수
        v.push_back({d, p});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        res += v[i].second;
        q.push(v[i].second);
        if (q.size() > v[i].first)
        {
            res -= q.top();
            q.pop();
        }
    }
    cout << res << "\n";
}
