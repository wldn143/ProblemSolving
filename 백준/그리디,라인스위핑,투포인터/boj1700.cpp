#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int n, k, d, plug[101], cur, cnt, mx, idx;
queue<int> q[101];
vector<int> dev;
set<int> dev_set;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> d;
        dev.push_back(d);
        dev_set.insert(d);
        if (cur < n)
        {
            if (!plug[d])
            {
                plug[d] = 1;
                cur++;
            }
        }
        q[d].push(i);
    }

    for (int i = 0; i < k; i++)
    {
        mx = 0;
        if (plug[dev[i]])
        {
            q[dev[i]].pop();
            continue;
        }

        for (auto a : dev_set)
        {
            if (plug[a])
            {
                if (!q[a].empty())
                {
                    if (q[a].front() > mx)
                    {
                        mx = q[a].front();
                        idx = a;
                    }
                }

                if (q[a].empty())
                {
                    idx = a;
                    break;
                }
            }
        }
        plug[idx] = 0, plug[dev[i]] = 1;

        q[dev[i]].pop();
        cnt++;
    }
    cout << cnt << "\n";
}
