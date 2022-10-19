#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, neigh_cnt, neigh, res = 987654321;
int p[11]; //각 구역의 인구수
int m[11][11], visited[11];
vector<int> a, b;
void dfs(int st, vector<int> v)
{
    visited[st] = 1;
    for (int x : v)
    {
        if (visited[x])
            continue;
        if (m[st][x])
        {
            dfs(x, v);
        }
    }
}
int check(vector<int> v)
{
    for (int x : v)
    {
        if (!visited[x])
            return 0;
    }
    return 1; //연결된 상태
}
void count()
{
    int a_cnt = 0, b_cnt = 0;
    for (int x : a)
        a_cnt += p[x];
    for (int x : b)
        b_cnt += p[x];
    int gap = a_cnt - b_cnt;
    res = min(res, abs(gap));
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    for (int i = 1; i <= n; i++)
    {
        cin >> neigh_cnt;
        for (int j = 0; j < neigh_cnt; j++)
        {
            cin >> neigh;
            m[i][neigh] = 1;
        }
    }

    for (int i = 1; i < (1 << n); i++)
    {
        fill(&visited[0], &visited[0] + 11, 0);
        a.clear();
        b.clear();
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {                       // 2진수로 나타낸 i의 j번째 비트가 1이면
                a.push_back(j + 1); //구역을 a 선거구에 넣기
            }
            else
            {
                b.push_back(j + 1);
            }
        }
        //각 경로가 연결되는지 체크

        int can = 0;
        dfs(a[0], a);
        can += check(a);
        dfs(b[0], b);
        can += check(b);

        if (can == 2) //두 구역 다 가능
            count();
    }
    if (res == 987654321)
        cout << -1 << "\n";
    else
        cout << res << "\n";
}
