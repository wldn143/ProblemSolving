#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, x, s, e, res;
vector<int> a;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        a.push_back(m);
    }
    sort(a.begin(), a.end());
    cin >> x;
    e = n - 1;
    s = 0;
    while (e > s)
    {
        if (a[s] + a[e] == x)
        {
            res++;
            s++;
        }
        else if (a[s] + a[e] > x)
            e--;
        else if (a[s] + a[e] < x)
            s++;
    }
    cout << res << "\n";
}
