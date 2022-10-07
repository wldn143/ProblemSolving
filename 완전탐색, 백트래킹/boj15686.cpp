#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stdio.h>
using namespace std;
int n, m, c_total;
int a[51][51];
vector<pair<int, int>> chicken;
vector<int> comb, v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 2)
            {
                chicken.push_back({i, j}); //치킨집 위치 저장
                c_total++;
            }
        }
    }

    for (int i = 0; i < c_total - m; i++)
    {
        comb.push_back(0);
    }
    for (int i = 0; i < m; i++)
    {
        comb.push_back(1);
    }

    do
    {
        vector<pair<int, int>> b;
        for (int i = 0; i < comb.size(); i++)
        {
            if (comb[i] == 1)
            {
                b.push_back({chicken[i].first, chicken[i].second});
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 1)
                {
                    int dist = 100;
                    for (int k = 0; k < m; k++)
                    {
                        int tmp = abs(i - b[k].first) + abs(j - b[k].second);
                        dist = min(dist, tmp);
                    }
                    res += dist;
                }
            }
        }
        v.push_back(res);
    } while (next_permutation(comb.begin(), comb.end()));

    sort(v.begin(), v.end());
    cout << v[0] << "\n";
}
