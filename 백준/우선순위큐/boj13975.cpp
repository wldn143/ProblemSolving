#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 987654321
#define ll long long
using namespace std;
int t, k;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--)
    {
        ll ret = 0;

        cin >> k;
        while (k--)
        {
            int x;
            cin >> x;
            pq.push(x);
        }

        while (pq.size())
        {
            ll a, b;
            a = pq.top();
            if (pq.size() == 1)
            {
                pq.pop();
                break;
            }
            pq.pop();
            b = pq.top();
            ret += (a + b);
            pq.pop();
            pq.push(a + b);
        }
        cout << ret << "\n";
    }
}
