#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m, ret, flag;
void go(ll k, ll cnt)
{
    if (k > m)
        return;
    if (k == m)
    {
        cout << cnt << "\n";
        flag = 1;
        return;
    }
    go(k * 2, cnt + 1);
    go(k * 10 + 1, cnt + 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    go(n, 1);
    if (!flag)
        cout << -1 << "\n";
}