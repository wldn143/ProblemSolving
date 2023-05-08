#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int t, k, n, x, check[1000001];
char cmd;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--)
    {
        priority_queue<pair<int, int>> max_heap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> cmd >> n;
            switch (cmd)
            {
            case 'I':
                min_heap.push({n, i});
                max_heap.push({n, i});
                check[i] = 1;
                break;

            case 'D':
                switch (n)
                {
                case 1:
                    while (max_heap.size())
                    {
                        x = max_heap.top().second;
                        if (check[x])
                        {
                            check[x] = 0;
                            max_heap.pop();
                            break;
                        }
                        max_heap.pop();
                    }
                    break;
                case -1:
                    while (min_heap.size())
                    {
                        x = min_heap.top().second;
                        if (check[x])
                        {
                            check[x] = 0;
                            min_heap.pop();
                            break;
                        }
                        min_heap.pop();
                    }
                    break;
                }
            }
        }
        while (max_heap.size())
        {
            x = max_heap.top().second;
            if (check[x])
                break;
            max_heap.pop();
        }
        while (min_heap.size())
        {
            x = min_heap.top().second;
            if (check[x])
                break;
            min_heap.pop();
        }
        if (min_heap.empty() || max_heap.empty())
            cout << "EMPTY\n";
        else
            cout << max_heap.top().first << " " << min_heap.top().first << "\n";
    }
}