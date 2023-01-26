#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, num[1000001];
vector<int> v;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    for (int i = 0; i < n; i++)
    {
        if (v.empty())
            v.push_back(num[i]);
        else
        {
            if (v[v.size() - 1] < num[i])
                v.push_back(num[i]);
            else
                *lower_bound(v.begin(), v.end(), num[i]) = num[i];
        }
    }
    cout << v.size() << "\n";
    return 0;
}