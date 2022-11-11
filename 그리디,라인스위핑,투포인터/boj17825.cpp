#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> m = {0, 1, 2, 3}, mm(10), a(10), b, v(32);
int mx, l[4], visited[32];

int go()
{
    int res = 0;
    for (int i = 0; i < 10; i++)
    {
        int mal = mm[i];
        int st = l[mal];
        int location = l[mal];
        int flag = 0;

        for (int j = 0; j < a[i]; j++)
        {
            if (location == 5 && j == 0)
                location = 21;
            else if (location == 10 && j == 0)
                location = 27;
            else if (location == 15 && j == 0)
                location = 29;
            else if (location == 31 || location == 28)
                location = 24;
            else if (location == 26)
                location = 20;
            else if (location == 20)
            {
                flag = 1;
                break;
            }
            else
                location++;
        }

        if (visited[location])
            return -1;
        if (flag)
            visited[st] = 0;
        else
        {
            visited[st] = 0, visited[location] = 1;
            l[mal] = location;
            res += v[location];
        }
    }
    return res;
}

void dfs(int idx, int cnt)
{
    if (cnt == 10)
    {
        do
        {
            fill(&visited[0], &visited[0] + 32, 0);
            fill(&l[0], &l[0] + 4, 0);
            int tmp = go();
            mx = max(mx, tmp);
        } while (next_permutation(mm.begin(), mm.end()));
        return;
    }
    for (int i = idx; i < m.size(); i++)
    {
        mm[cnt] = m[i];
        dfs(i, cnt + 1);
    }
}
int main()
{
    for (int i = 0; i < 10; i++)
        cin >> a[i];
    v[1] = 2, v[2] = 4, v[3] = 6, v[4] = 8, v[5] = 10, v[6] = 12,
    v[7] = 14, v[8] = 16, v[9] = 18, v[10] = 20, v[11] = 22,
    v[12] = 24, v[13] = 26, v[14] = 28, v[15] = 30, v[16] = 32,
    v[17] = 34, v[18] = 36, v[19] = 38, v[20] = 40, v[21] = 13,
    v[22] = 16, v[23] = 19, v[24] = 25, v[27] = 22, v[28] = 24,
    v[25] = 30, v[26] = 35, v[29] = 28, v[30] = 27, v[31] = 26;
    dfs(0, 0);
    cout << mx << "\n";
}
