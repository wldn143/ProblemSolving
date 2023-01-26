#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, k, m, v;
long long res, c;
vector<pair<int, int>> jew;
vector<int> bag;
priority_queue<int, vector<int>, less<int>> pq;
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> m >> v;
        jew.push_back({m, v});
    }
    for (int i = 0; i < k; i++)
    {
        cin >> c;
        bag.push_back(c);
    }
    sort(jew.begin(), jew.end());
    sort(bag.begin(), bag.end());

    int j = 0;
    for (int i = 0; i < k; i++)
    {
        while (j < n && bag[i] >= jew[j].first)
        {
            pq.push(jew[j].second);
            j++;
        }
        if (!pq.empty())
        {
            res += pq.top();
            pq.pop();
        }
    }
    cout << res << "\n";
}
