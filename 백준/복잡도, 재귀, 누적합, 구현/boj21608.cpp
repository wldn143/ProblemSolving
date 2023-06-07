#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, ret;
int map[21][21];
int like_list[401][4];
int d[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
struct info
{
    int like_cnt, empty_cnt, y, x;
};

bool cmp(info a, info b)
{
    if (a.like_cnt == b.like_cnt)
    {
        if (a.empty_cnt == b.empty_cnt)
        {
            if (a.y == b.y)
                return a.x < b.x;
            return a.y < b.y;
        }
        return a.empty_cnt > b.empty_cnt;
    }
    return a.like_cnt > b.like_cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int t = 1; t <= n * n; t++)
    {
        int num;
        cin >> num >> like_list[num][0] >> like_list[num][1] >> like_list[num][2] >> like_list[num][3];

        vector<info> v;

        // 좋아하는 학생 수 가장 많이 인접한 칸 max값 구하기, like배열에 좋학수 저장
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!map[i][j]) // 들어갈 수 있는 칸이면
                {
                    int like = 0;  // map[i][j]인근에 좋아하는 학생 수 몇명인지
                    int empty = 0; // map[i][j]인근에 빈칸이 몇개인지

                    for (int k = 0; k < 4; k++) // 4방 탐색
                    {
                        int ny = i + d[k][0];
                        int nx = j + d[k][1];

                        if (ny < 0 || nx < 0 || ny >= n || nx >= n)
                            continue;

                        if (map[ny][nx] == 0)
                            empty++;

                        for (int l = 0; l < 4; l++) // 사방에 좋아하는 학생 수는
                            if (map[ny][nx] == like_list[num][l])
                                like++;
                    }
                    v.push_back({like, empty, i, j});
                }
            }
        }
        sort(v.begin(), v.end(), cmp);
        map[v[0].y][v[0].x] = num;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int w = 0;
            int num = map[i][j];
            for (int k = 0; k < 4; k++) // 4방 탐색
            {
                int ny = i + d[k][0];
                int nx = j + d[k][1];

                if (ny < 0 || nx < 0 || ny >= n || nx >= n)
                    continue;

                for (int l = 0; l < 4; l++) // 사방에 좋아하는 학생 수
                    if (map[ny][nx] == like_list[num][l])
                        w++;
            }
            if (w == 1)
                ret += 1;
            else if (w == 2)
                ret += 10;
            else if (w == 3)
                ret += 100;
            else if (w == 4)
                ret += 1000;
        }
    }
    cout << ret;
}
