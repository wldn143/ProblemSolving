#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <cmath>
using namespace std;
int t, dir[5];
vector<deque<char>> v;
deque<char> dq;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    v.push_back(dq);

    for (int i = 1; i <= 4; i++)
    {
        string s;
        cin >> s;
        for (char a : s)
            dq.push_back(a);
        v.push_back(dq);
        dq.clear();
    }

    cin >> t;

    while (t--)
    {
        int n, d;
        cin >> n >> d;

        dir[n] = d;
        for (int i = n; i < 4; i++)
        {
            if (v[i][2] != v[i + 1][6])
                dir[i + 1] = dir[i] * -1;
            else
                dir[i + 1] = 0;
        }
        for (int i = n; i > 1; i--)
        {
            if (v[i][6] != v[i - 1][2])
                dir[i - 1] = dir[i] * -1;
            else
                dir[i - 1] = 0;
        }

        for (int i = 1; i <= 4; i++)
        {
            if (dir[i] == 1)
            {
                char a = v[i].back();
                v[i].pop_back();
                v[i].push_front(a);
            }
            else if (dir[i] == -1)
            {
                char a = v[i].front();
                v[i].pop_front();
                v[i].push_back(a);
            }
        }
    }
    int ret = 0;

    for (int i = 0; i < 4; i++)
    {
        if (v[i + 1][0] == '1')
            ret += pow(2, i);
    }
    cout << ret;
}
