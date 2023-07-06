#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 987654321
int n, m, k;
int map[1001][1001], dp[1001][1001][11];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
queue<pair<pair<int, int>, int>> q;

int bfs()
{
    while (q.size())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;

        if (y == n - 1 && x == m - 1)
            return dp[y][x][cnt];

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;

            if (!map[ny][nx] && !dp[ny][nx][cnt])
            {
                q.push({{ny, nx}, cnt});
                dp[ny][nx][cnt] = dp[y][x][cnt] + 1;
            }

            if (map[ny][nx] && cnt < k && !dp[ny][nx][cnt + 1])
            {
                q.push({{ny, nx}, cnt + 1});
                dp[ny][nx][cnt + 1] = dp[y][x][cnt] + 1;
            }
        }
        q.pop();
    }
    return -1;
}
int main()
{
    // iostream, stdio 싱크 끊는 코드 써서 계속 틀림 ㅗ
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &map[i][j]);

    // dp[y좌표][x좌표][부순 벽 수]
    q.push({{0, 0}, 0});
    dp[0][0][0] = 1;
    cout << bfs();
}
