#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, map[21][21], s_y, s_x, s_size = 2, result, cnt;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int visited[21][21], eat[21][21];
queue<pair<int, int>> q;

void bfs()
{
    while (q.size())
    {
        int y, x;
        tie(y, x) = q.front();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] || map[ny][nx] > s_size)
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            if (map[ny][nx] && map[ny][nx] < s_size)
                eat[ny][nx] = 1;
            q.push({ny, nx});
        }
        q.pop();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 9)
            {
                s_y = i;
                s_x = j;
            }
        }
    }

    while (1)
    {
        visited[s_y][s_x] = 1;
        q.push({s_y, s_x});
        bfs();
        int MIN = 500;
        int flag = 0;
        map[s_y][s_x] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] > 1 && visited[i][j] < MIN && eat[i][j])
                {
                    s_y = i, s_x = j;
                    MIN = visited[i][j];
                    flag = 1;
                }
                visited[i][j] = 0;
                eat[i][j] = 0;
            }
        }
        if (!flag)
            break;
        cnt++;
        result += (MIN - 1);

        if (cnt == s_size)
        {
            s_size++;
            cnt = 0;
        }
    }
    cout << result;
}