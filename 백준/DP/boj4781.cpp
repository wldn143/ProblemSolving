#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int n, m1, m2, wallet, c, p, dp[10001];
int main()
{
    while (1)
    {
        scanf("%d %d.%d", &n, &m1, &m2);
        if (!n && !m1 && !m2)
            break;
        wallet = m1 * 100 + m2;
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++)
        {
            scanf("%d %d.%d", &c, &m1, &m2);
            p = m1 * 100 + m2;

            for (int j = p; j <= wallet; j++)
            {
                dp[j] = max(dp[j], dp[j - p] + c);
            }
        }
        cout << dp[wallet] << "\n";
    }
}