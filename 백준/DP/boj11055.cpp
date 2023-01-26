#include <iostream>
#include <algorithm>
using namespace std;
int n, a[1001], dp[1001], hop[1001], ret;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        hop[i] = a[i];
    }

    for (int i = 0; i < n; i++)
    {
        int h = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                h = max(h, hop[j]);
            }
        }
        hop[i] += h;
        ret = max(ret, hop[i]);
    }
    cout << ret << "\n";
}