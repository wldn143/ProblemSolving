#include <iostream>
#include <algorithm>
using namespace std;
int n, a, sum, res = -1001;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        sum += a;
        res = max(res, sum);
        if (sum < 0)
            sum = 0;
    }
    cout << res << "\n";
}
