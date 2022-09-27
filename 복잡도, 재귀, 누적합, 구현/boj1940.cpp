#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> v;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int start = 0, end = n - 1, cnt = 0;
    while (end > start)
    {
        if (v[start] + v[end] == m)
        {
            cnt++;
            start++;
            end--;
        }
        else if (v[start] + v[end] > m)
        {
            end--;
        }
        if (v[start] + v[end] < m)
        {
            start++;
        }
    }
    cout << cnt << "\n";
}