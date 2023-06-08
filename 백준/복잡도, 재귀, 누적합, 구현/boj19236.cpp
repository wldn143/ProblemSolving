#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct FISH
{
    int num, d;
};
struct L
{
    int y, x, d;
};
FISH map[5][5];
int ret;
int dir[9][2] = {{0, 0}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

void go(int s_y, int s_x, FISH arr[5][5], int sum)
{
    sum += arr[s_y][s_x].num;
    arr[s_y][s_x].num = -1;

    vector<int> move_list; // 움직일 물고기 번호 벡터
    L location[17];        // 번호 별 물고기의 위치, 방향 저장

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (arr[i][j].num > 0)
            {
                move_list.push_back(arr[i][j].num);
                location[arr[i][j].num] = {i, j, arr[i][j].d};
            }

    sort(move_list.begin(), move_list.end());

    for (int n : move_list)
    {
        int y = location[n].y;
        int x = location[n].x;
        int d = location[n].d - 1;

        for (int i = 0; i < 8; i++)
        {
            d++;
            if (d == 9)
                d = 1;

            int ny = y + dir[d][0];
            int nx = x + dir[d][1];

            if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4 || arr[ny][nx].num == -1)
                continue;

            arr[y][x] = {arr[ny][nx].num, arr[ny][nx].d};
            location[arr[ny][nx].num] = {y, x, arr[ny][nx].d};
            arr[ny][nx] = {n, d};
            location[n] = {ny, nx, d};
            break;
        }
    }

    // 상어 이동
    int d = arr[s_y][s_x].d;
    int flag = 0;

    for (int i = 1; i <= 3; i++) // 방향으로 3칸 이동 가능
    {
        int ny = s_y + dir[d][0] * i;
        int nx = s_x + dir[d][1] * i;

        if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4 || arr[ny][nx].num == 0)
            continue;

        FISH tmp[5][5];
        flag = 1;

        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                tmp[j][k] = arr[j][k];

        tmp[s_y][s_x] = {0, 0};

        go(ny, nx, tmp, sum);
    }

    if (!flag)
    {
        ret = max(ret, sum);
        return;
    }
}

int main()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> map[i][j].num >> map[i][j].d;

    go(0, 0, map, 0);

    cout << ret;
}
