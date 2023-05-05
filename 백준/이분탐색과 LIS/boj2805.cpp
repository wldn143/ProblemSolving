#include <iostream>
#include <algorithm>
using namespace std;
int n, m, tree[1000001];
int low, high, mid;
long long result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
        if (high < tree[i])
            high = tree[i];
    }

    while (low <= high)
    {
        long long sum = 0;
        mid = (high + low) / 2;
        for (int i = 0; i < n; i++)
            if (tree[i] > mid)
                sum += tree[i] - mid;

        if (sum < m)
            high = mid - 1;

        else
        {
            result = mid;
            low = mid + 1;
        }
    }
    cout << result;
}