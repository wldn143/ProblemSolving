#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int r, c, k, ret;
int map[101][101];
int cnt[101];
set<int> st;
vector<pair<int, int>> tmp;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> k;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> map[i][j];

    int a = 3, b = 3; // 열개수, 행개수

    while (1)
    {
        if (map[r - 1][c - 1] == k)
        {
            cout << ret;
            break;
        }
        ret++;
        if (ret > 100)
        {
            cout << -1;
            break;
        }
        int flag = 0, a_cnt = 0;

        if (b >= a)
            flag = 1;

        if (flag) // 행정렬
        {
            for (int i = 0; i < b; i++)
            {
                for (int j = 0; j < a; j++)
                {
                    if (!map[i][j])
                        continue;
                    st.insert(map[i][j]);
                    cnt[map[i][j]]++;
                    map[i][j] = 0;
                }

                for (int s : st)
                {
                    tmp.push_back({s, cnt[s]});
                    cnt[s] = 0;
                }

                int st_size = st.size();
                a_cnt = max(a_cnt, st_size * 2);

                st.clear();

                sort(tmp.begin(), tmp.end(), cmp);

                int idx = 0;
                for (auto t : tmp)
                {
                    map[i][idx] = t.first;
                    map[i][idx + 1] = t.second;
                    idx += 2;
                    if (idx == 98)
                        break;
                }
                tmp.clear();
            }
        }

        else
        {
            for (int i = 0; i < a; i++)
            {
                vector<pair<int, int>> tmp;

                for (int j = 0; j < b; j++)
                {
                    if (!map[j][i])
                        continue;
                    st.insert(map[j][i]);
                    cnt[map[j][i]]++;
                    map[j][i] = 0;
                }

                for (int s : st)
                {
                    tmp.push_back({s, cnt[s]});
                    cnt[s] = 0;
                }

                int st_size = st.size();
                a_cnt = max(a_cnt, st_size * 2);

                st.clear();

                sort(tmp.begin(), tmp.end(), cmp);

                int idx = 0;
                for (auto t : tmp)
                {
                    map[idx][i] = t.first;
                    map[idx + 1][i] = t.second;
                    idx += 2;
                    if (idx == 98)
                        break;
                }
                tmp.clear();
            }
        }

        if (flag)
            a = a_cnt;
        else
            b = a_cnt;
    }
}
