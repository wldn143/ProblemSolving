#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 987654321;
struct A
{
    int y, x;
};
int n, m, house_cnt;
vector<A> house;
vector<A> chicken;
vector<int> dis[101];
int main()
{
    cin >> n >> m;
    int chicken_num = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int k;
            cin >> k;
            if (k == 1)
            {
                house.push_back({i, j});
                house_cnt++;
            }
            if (k == 2)
                chicken.push_back({i, j});
        }
    }

    for (int i = 0; i < house.size(); i++)
    {
        auto h = house[i];
        for (auto c : chicken)
            dis[i].push_back({abs(h.y - c.y) + abs(h.x - c.x)});
        // 1번 집에서 1~5번까지의 치킨 거리
    }

    // 조합 만들기
    vector<int> com;
    vector<int> mask;

    for (int i = 0; i < chicken.size(); i++)
        com.push_back(i);

    for (int i = 0; i < chicken.size() - m; i++)
        mask.push_back(0);

    for (int i = 0; i < m; i++)
        mask.push_back(1);

    int ret = MAX;

    do
    {
        int sum = 0;
        int min_dis; // 각 집에서 mask에 해당하는 치킨집까지의 거리의 최소
        for (int i = 0; i < house_cnt; i++)
        {
            min_dis = MAX;
            for (int j = 0; j < mask.size(); j++) // 11100
            {
                if (mask[j])
                {
                    min_dis = min(min_dis, dis[i][j]);
                }
            }
            sum += min_dis;
        }
        ret = min(ret, sum);
    } while (next_permutation(mask.begin(), mask.end()));

    cout << ret;
}
