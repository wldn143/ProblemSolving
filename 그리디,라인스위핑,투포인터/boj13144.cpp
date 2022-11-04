#include <iostream>
#include <algorithm>
using namespace std;
int n, s, e, a[100001], cnt[100001];
long long res;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    while (e < n)
    {
        if (!cnt[a[e]])
        {
            cnt[a[e]]++;
            e++;
        }
        else
        {
            res += (e - s);
            cnt[a[s]]--;
            s++;
        }
    }
    for (int i = 1; i <= e - s; i++)
    {
        res += i;
    }
    cout << res << "\n";
}
