#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, k, l, a[101][101], apple[101][101], visited[101][101], s, y, x, cur;
queue<pair<int, char>> rot;
queue<pair<int, int>> tail;
pair<int, int> head, state[4];
int main()
{
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int a1, a2;
        cin >> a1 >> a2;
        apple[a1][a2] = 1;
    }
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int sec;
        char d;
        cin >> sec >> d;
        rot.push({sec, d});
    }
    state[0] = {0, 1};
    state[1] = {1, 0};
    state[2] = {0, -1};
    state[3] = {-1, 0};
    y = 1, x = 1;
    while (1)
    {
        tail.push({x, y});
        y = y + state[s].second;
        x = x + state[s].first;
        if (y > n || x > n || y <= 0 || x <= 0 || visited[x][y])
            break;
        if (!apple[x][y])
        {
            auto t = tail.front();
            visited[t.first][t.second] = 0;
            tail.pop();
        }
        apple[x][y] = 0;
        visited[x][y] = 1;
        head.first = x, head.second = y;

        cur++;
        auto r = rot.front();
        if (cur == r.first)
        {
            if (r.second == 'D')
            {
                s += 1;
                if (s == 4)
                    s = 0;
            }
            else
            {
                s -= 1;
                if (s == -1)
                    s = 3;
            }
            rot.pop();
        }
    }
    cout << cur + 1 << "\n";
}
