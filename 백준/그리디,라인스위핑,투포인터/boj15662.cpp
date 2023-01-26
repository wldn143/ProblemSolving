#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int t, k, res, isR[1001];
queue<pair<int, int>> rot;
string s[1001];
void go()
{
    for (int i = 0; i < t; i++)
    {
        if (isR[i] == 1)
            rotate(s[i].begin(), s[i].begin() + s[i].size() - 1, s[i].end());
        else if (isR[i] == -1)
            rotate(s[i].begin(), s[i].begin() + 1, s[i].end());
    }
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
        cin >> s[i];
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int num, dir;
        cin >> num >> dir;
        rot.push({num - 1, dir});
    }

    while (rot.size())
    {
        int cmd = rot.front().second;
        int r = rot.front().first, l = rot.front().first;
        isR[r] = cmd;
        for (int i = rot.front().first - 1; i >= 0; i--)
        {
            if (!cmd)
            {
                isR[i] = 0;
                continue;
            }
            if (s[r][6] == s[i][2])
            {
                isR[i] = 0;
                cmd = 0;
            }
            else
            {
                cmd *= -1;
                isR[i] = cmd;
                r = i;
            }
        }
        cmd = rot.front().second;
        for (int i = rot.front().first + 1; i < t; i++)
        {
            if (!cmd)
            {
                isR[i] = 0;
                continue;
            }
            if (s[i][6] == s[l][2])
            {
                isR[i] = 0;
                cmd = 0;
            }
            else
            {
                cmd *= -1;
                isR[i] = cmd;
                l = i;
            }
        }
        go();
        rot.pop();
    }
    for (int i = 0; i < t; i++)
        res += (s[i][0] - '0');
    cout << res << "\n";
}