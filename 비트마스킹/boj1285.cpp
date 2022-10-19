#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
char origin[21][21], m[21][21];
vector<int> res;
void reverse_c(int x) //열뒤집기 ||
{
    for (int i = 0; i < n; i++)
    {
        if (m[i][x] == 'T')
        {
            m[i][x] = 'H';
        }
        else if (m[i][x] == 'H')
            m[i][x] = 'T';
    }
}
void reverse_r(int y) //행뒤집기 --
{
    for (int i = 0; i < n; i++)
    {
        if (m[y][i] == 'T')
            m[y][i] = 'H';
        else if (m[y][i] == 'H')
            m[y][i] = 'T';
    }
}
void count()
{
    int t_cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (m[i][j] == 'T')
                t_cnt++;
        }
    }
    res.push_back(t_cnt);
}
void check()
{
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (m[i][j] == 'T')
                cnt++;
        }
        if (cnt >= (n / 2))
            reverse_r(i);
    }
}
void m_copy()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            m[i][j] = origin[i][j];
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> origin[i][j];
        }
    }

    for (int i = 0; i < (1 << n); i++)
    {
        m_copy();
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                reverse_c(j);
            }
        }
        check();
        count();
    }
    sort(res.begin(), res.end());
    cout << res[0] << "\n";
}
