#include <iostream>
#include <algorithm>
using namespace std;
int n, a[1001], l[1001], mx = -1;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        l[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
                l[i] = max(l[i], l[j] + 1);
        }
        mx = max(mx, l[i]);
    }
    cout << mx << "\n";
    return 0;
}
