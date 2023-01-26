#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, k, cnt, t, r, mn = 100000, mx = 100000;
queue<pair<int, int>> q;
bool visited[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    visited[n] = 1;
    q.push({n, 0});

    while (q.size())
    {
        tie(t, r) = q.front();
        q.pop();
        visited[t] = 1;
        if (mn < r)
            break;
        if (t == k)
        {
            mn = r;
            cnt++;
            continue;
        }
        if (t + 1 <= mx && !visited[t + 1])
        {
            q.push({t + 1, r + 1});
        }
        if (t - 1 >= 0 && !visited[t - 1])
        {
            q.push({t - 1, r + 1});
        }
        if (t * 2 <= mx && !visited[t * 2])
        {
            q.push({t * 2, r + 1});
        }
    }
    cout << mn << "\n"
         << cnt;
}
