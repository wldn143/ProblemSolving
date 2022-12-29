#include <iostream>
#include <algorithm>
using namespace std;
int n, m, c, a[14], dp[11][1 << 13][21];

int go(int bagNum, int yam, int capacity)
{
    if (bagNum == m)
        return 0;
    int &ret = dp[bagNum][yam][capacity];
    if (ret)
        return ret;
    ret = max(ret, go(bagNum + 1, yam, c));
    for (int i = 0; i < n; i++)
    {
        bool beforeYam = (1 << i) & yam;
        bool canYam = (capacity - a[i]) >= 0;
        if (canYam && !beforeYam)
            ret = max(ret, go(bagNum, yam | (1 << i), capacity - a[i]) + 1);
    }
    return ret;
}
int main()
{
    cin >> n >> m >> c;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << go(0, 0, c) << "\n";
}