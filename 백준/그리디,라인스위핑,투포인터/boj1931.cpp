#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, s, f, fin, res;
vector<pair<int, int>> v;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> f;
        v.push_back({s, f}); //시작시간, 종료시간
    }
    sort(v.begin(), v.end(), cmp); //종료시간 더 빠른순으로 정렬
    fin = v[0].second;
    for (int i = 0; i < v.size(); i++)
    {
        // flag = 1;
        if (i > 0 && v[i].first >= fin)
        {
            fin = v[i].second;
            res++;
        }
    }
    cout << res + 1 << "\n";
}
