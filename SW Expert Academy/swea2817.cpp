#include <iostream>
#include <algorithm>
using namespace std;
int T, n, k, a[20], cnt;
void go(int idx, int sum)
{
    if (sum == k)
    {
        cnt++;
        return;
    }
    for (int i = idx + 1; i < n; i++)
    {
        sum += a[i];
        go(i, sum);
        sum -= a[i];
    }
    return;
}
int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n >> k;
        cnt = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            go(i, a[i]);
        cout << "#" << t << " " << cnt << "\n";
    }
    return 0;
}