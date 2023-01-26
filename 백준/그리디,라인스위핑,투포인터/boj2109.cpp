#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, p, d, res, a[10001];
int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> d;
        q.push({p, d});
    }
    while (!q.empty())
    {
        for (int i = q.top().second; i >= 1; i--)
        {
            if (!a[i])
            {
                a[i] = 1;
                res += q.top().first;
                break;
            }
        }
        q.pop();
    }
    cout << res << "\n";
}
