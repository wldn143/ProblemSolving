#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, in, d, fin, start;
vector<pair<int, int>> v;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> in >> d;
        v.push_back({in, d});
    }
    sort(v.begin(), v.end());
    start = v[0].first;
    for (auto a : v)
    {
        if (fin)
        {
            if (fin < a.first)
                start = a.first;
            else
                start = fin;
        }
        fin = start + a.second;
    }
    cout << fin << "\n";
}
