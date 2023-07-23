#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef struct a
{
    int y;
    int x;
} dir;

int n;
string arr[50];
vector<dir> door;
int visited[50][50][4];
dir d[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs()
{

    queue<pair<pair<int, int>, int>> que; // 좌표 방향
    for (int i = 0; i < 4; i++)
    {
        que.push(make_pair(make_pair(door[0].y, door[0].x), i));
        visited[door[0].y][door[0].x][i] = 1;
    }

    while (!que.empty())
    {
        int y = que.front().first.first;
        int x = que.front().first.second;
        int dir = que.front().second;
        que.pop();

        int ny = y + d[dir].y;
        int nx = x + d[dir].x;
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || arr[ny][nx] == '*')
            continue;

        if (arr[ny][nx] == '.' || arr[ny][nx] == '#')
        {
            if (visited[ny][nx][dir] > visited[y][x][dir] || visited[ny][nx][dir] == 0)
            {
                visited[ny][nx][dir] = visited[y][x][dir];
                que.push(make_pair(make_pair(ny, nx), dir));
            }
        }
        else if (arr[ny][nx] == '!')
        {
            if (visited[ny][nx][dir] > visited[y][x][dir])
            { // 거울 설치 x
                visited[ny][nx][dir] = visited[y][x][dir];
                que.push(make_pair(make_pair(ny, nx), dir));
            }
            for (int i = 1; i <= 3; i += 2)
            {
                if (visited[ny][nx][(dir + i) % 4] > visited[y][x][dir] + 1)
                { // 거울 설치 1
                    visited[ny][nx][(dir + i) % 4] = visited[y][x][dir] + 1;
                    que.push(make_pair(make_pair(ny, nx), (dir + i) % 4));
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == '#')
                door.push_back({i, j});
            for (int k = 0; k < 4; k++)
                visited[i][j][k] = 2000000000;
        }
    }

    bfs();

    int result = 2000000000;
    for (int i = 0; i < 4; i++)
    {
        if (visited[door[1].y][door[1].x][i] != 0)
            result = min(result, visited[door[1].y][door[1].x][i]);
    }
    cout << result - 1 << endl;

    return 0;
}