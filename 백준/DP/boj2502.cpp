#include <iostream>
using namespace std;
int n, m, a, b, ret = 1;
string dp[31];

int main()
{
    cin >> n >> m;

    dp[1] = "a";
    dp[2] = "b";
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    for (char c : dp[n])
    {
        if (c == 'a')
            a++;
        else
            b++;
    }
    while (1)
    {
        int k = m - (ret * a);
        if (k % b == 0)
        {
            cout << ret << "\n"
                 << k / b << "\n";
            break;
        }
        else
            ret++;
    }
}