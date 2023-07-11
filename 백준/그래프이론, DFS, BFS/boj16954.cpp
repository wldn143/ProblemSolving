#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
char map[8][8];
int down[8][8][8];
int visited[8][8][8];
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
queue<pair<pair<int, int>, int>> q;
int main()
{

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            scanf("%1s", &map[i][j]);

    visited[7][0][0] = 1;
    q.push({{7, 0}, 0});
    int flag = 0;

    while (q.size())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;

        if (cnt >= 8 || (y == 0 && x == 7))
        {
            flag = 1;
            break;
        }

        for (int i = 0; i < 9; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8 || visited[ny][nx][cnt + 1])
                continue;
            if (ny - cnt >= 0 && map[ny - cnt][nx] == '#')
                continue;
            if (ny - cnt - 1 >= 0 && map[ny - cnt - 1][nx] == '#')
                continue;

            visited[ny][nx][cnt + 1] = 1;
            q.push({{ny, nx}, cnt + 1});
        }
        q.pop();
    }
    cout << flag;
}