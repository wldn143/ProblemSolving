#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int n, k, ret;
deque<pair<int, int>> dq;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n * 2; i++)
    {
        int x;
        cin >> x;
        dq.push_back({x, 0});
    }

    while (1)
    {
        ret++;
        auto a = dq.back();
        dq.pop_back();
        dq.push_front(a);

        dq[n - 1].second = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            if (dq[i].second == 1)
                if (dq[i + 1].first > 0 && dq[i + 1].second == 0)
                {
                    dq[i].second = 0;
                    dq[i + 1].first--;
                    dq[i + 1].second = 1;
                }
        }

        dq[n - 1].second = 0;

        if (dq[0].first > 0)
        {
            dq[0].first--;
            dq[0].second = 1;
        }

        int cnt = 0;

        for (int i = 0; i < 2 * n; i++)
            if (dq[i].first == 0)
                cnt++;
        if (cnt >= k)
            break;
    }

    cout << ret;
}
