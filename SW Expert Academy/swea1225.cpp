#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, a[101][101];
int main()
{
    for (int t = 1; t <= 10; t++)
    {
        cin >> n;
        vector<int> v(8);
        int cnt = 1;
        for (int i = 0; i < 8; i++)
            cin >> v[i];
        while (1)
        {
            if (cnt == 6)
                cnt = 1;
            v[0] -= cnt;
            rotate(v.begin(), v.begin() + 1, v.end());
            if (v[7] <= 0)
            {
                v[7] = 0;
                break;
            }
            cnt++;
        }
        cout << "#" << t << " ";
        for (int i : v)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}