#include <iostream>
using namespace std;
int k, m, n, res, a[1001], b[1001], Acnt[2000001], Bcnt[2000001];

void go(int p, int arr[], int cnt[])
{
    for (int i = 1; i <= p; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
            sum += arr[j];
        cnt[sum]++;
        if (sum == k)
            res++;
        if (i == p)
            break;
        for (int j = 1; j < p; j++)
        {
            sum -= arr[j - 1];
            sum += arr[(j + i - 1) % p];
            cnt[sum]++;
            if (sum == k)
                res++;
        }
    }
}

int main()
{
    cin >> k >> m >> n;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    go(m, a, Acnt);
    go(n, b, Bcnt);
    for (int i = 1; i < k; i++)
    {
        int j = k - i;
        res += Acnt[i] * Bcnt[j];
    }
    cout << res << "\n";
}
