#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#define MAX 987654321
#define ll long long
using namespace std;
int T, n, d, c, a, b, s;
int sec[10001];
queue<int> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--)
    {
        cin >> n >> d >> c;

        vector<pair<int, int>> connect[10001];

        fill_n(sec, 10001, MAX);
        sec[c] = 0;
        q.push(c);

        for (int i = 0; i < d; i++)
        {
            cin >> a >> b >> s;
            connect[b].push_back({a, s});
        }

        while (q.size())
        {
            int f = q.front();

            for (int i = 0; i < connect[f].size(); i++)
            {
                int nxt = connect[f][i].first;
                int nxtTime = sec[f] + connect[f][i].second;

                if (nxtTime < sec[nxt])
                {
                    sec[nxt] = nxtTime;
                    q.push(nxt);
                }
            }
            q.pop();
        }

        int cnt = 0, ret_time = 0;

        for (int i = 1; i <= n; i++)
        {
            if (sec[i] != MAX)
            {
                cnt++;
                ret_time = max(ret_time, sec[i]);
            }
        }

        cout << cnt << " " << ret_time << "\n";
    }
}
