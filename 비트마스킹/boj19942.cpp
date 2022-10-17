#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, cost, flag, mx = 987654321, m_cost, nut[4], a[15][5];
vector<int> v;
vector<vector<int>> result[7501];
int main()
{
    cin >> n;
    for (int i = 0; i < 4; i++)
        cin >> nut[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> a[i][j];
        }
    }
    m_cost = mx;
    for (int i = 1; i < (1 << n); i++)
    {
        int ret[5] = {0, 0, 0, 0};
        flag = 1;
        cost = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                for (int k = 0; k < 4; k++)
                {
                    ret[k] += a[j][k];
                }
                cost += a[j][4];
                v.push_back(j + 1);
            }
        }
        for (int l = 0; l < 4; l++)
        {
            if (nut[l] > ret[l])
                flag = 0;
        }
        if (flag && cost <= m_cost)
        {
            result[cost].push_back(v);
            m_cost = cost;
        }
        v.clear();
    }
    if (m_cost == mx)
        cout << -1 << "\n";
    else
    {
        cout << m_cost << "\n";
        sort(result[m_cost].begin(), result[m_cost].end());
        for (int i : result[m_cost][0])
            cout << i << " ";
    }
}
