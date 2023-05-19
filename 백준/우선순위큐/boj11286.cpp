#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, x;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while (n--)
    {
        cin >> x;
        if (!x)
        {
            if (pq.empty())
                cout << 0 << "\n";
            else
            {
                cout << pq.top().second << "\n";
                pq.pop();
            }
        }
        else
            pq.push({abs(x), x});
    }
}