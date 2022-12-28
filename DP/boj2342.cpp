#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int t, dp[5][5][100001];
vector<int> v;
int check(int from, int to)
{
    if (from == 0)
        return 2;
    if (from == to)
        return 1;
    if (abs(from - to) == 2)
        return 4;
    return 3;
}
int solve(int y, int x, int target)
{
    if (target == v.size())
        return 0;
    if (dp[y][x][target] != -1)
        return dp[y][x][target];

    int left = solve(v[target], x, target + 1) + check(y, v[target]);
    int right = solve(y, v[target], target + 1) + check(x, v[target]);

    return dp[y][x][target] = min(left, right);
}

int main()
{
    while (1)
    {
        cin >> t;
        if (!t)
            break;
        else
            v.push_back(t);
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, 0) << "\n";
}