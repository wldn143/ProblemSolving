#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int n, k, res;
deque<int> d[100];
int main()
{
    for (int t = 1; t <= 10; t++)
    {
        cin >> n;
        res = 0;
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++)
            {
                cin >> k;
                if (k)
                    d[j].push_back(k);
            }

        for (int i = 0; i < 100; i++)
        {
            while (d[i].size() && d[i].front() == 2)
                d[i].pop_front();
            while (d[i].size() && d[i].back() == 1)
                d[i].pop_back();
            int cur = 0;
            while (d[i].size())
            {
                cur = d[i].front();
                d[i].pop_front();
                if (cur == 1 && d[i].front() == 2)
                {
                    res++;
                    d[i].pop_front();
                }
            }
            d[i].clear();
        }
        cout << "#" << t << " " << res << "\n";
    }
    return 0;
}