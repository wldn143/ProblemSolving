#include <iostream>
#include <algorithm>
using namespace std;
long long t, dp[31][31];
long long go(int w, int h)
{
    if (w == t && h == t)
        return 1;
    if (w > t || h > t)
        return 0;
    if (dp[w][h])
        return dp[w][h];
    if (w > h)
        dp[w][h] += go(w, h + 1);
    dp[w][h] += go(w + 1, h);

    return dp[w][h];
}
int main()
{
    while (1)
    {
        cin >> t;
        if (!t)
            break;
        cout << go(1, 0) << "\n";
        fill(&dp[0][0], &dp[0][0] + 31 * 31, 0);
    }
}
