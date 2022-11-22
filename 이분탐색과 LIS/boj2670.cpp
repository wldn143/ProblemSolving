#include <iostream>
#include <algorithm>
using namespace std;
int n;
double a[10001], dp[10001], mx;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
            dp[i] = a[i];
        else
            dp[i] = max(a[i], dp[i - 1] * a[i]);
        mx = max(mx, dp[i]);
    }
    printf("%.3f\n", mx);
    return 0;
}