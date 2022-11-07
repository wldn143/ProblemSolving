#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, a[21][21], cap_a, cap_b, res = 987654321;
vector<int> team_a, team_b;
void go()
{
    for (int i = 0; i < team_a.size(); i++)
    {
        int a1 = team_a[i], b1 = team_b[i];
        for (int j = 0; j < team_a.size(); j++)
        {
            int a2 = team_a[j], b2 = team_b[j];
            cap_a += a[a1][a2];
            cap_b += a[b1][b2];
        }
    }
    res = min(res, abs(cap_a - cap_b));
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }

    for (int i = 1; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                team_a.push_back(j + 1);
            else
                team_b.push_back(j + 1);
        }
        if (team_a.size() == (n / 2))
            go();
        team_a.clear();
        team_b.clear();
        cap_a = 0;
        cap_b = 0;
    }
    cout << res << "\n";
}
