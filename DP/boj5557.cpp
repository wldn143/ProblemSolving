#include <iostream>
using namespace std;
typedef long long ll;
int n, a[101];
ll dp[101][21]; // 인덱스, 값
ll go(int idx, int sum)
{
    if (sum < 0 || sum > 20)
        return 0;
    if (idx == n - 2)
    {
        if (sum == a[n - 1])
            return 1;
        return 0;
    }
    if (dp[idx][sum])
        return dp[idx][sum];

    dp[idx][sum] += go(idx + 1, sum - a[idx + 1]);
    dp[idx][sum] += go(idx + 1, sum + a[idx + 1]);

    return dp[idx][sum];
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << go(0, a[0]) << "\n";
}
