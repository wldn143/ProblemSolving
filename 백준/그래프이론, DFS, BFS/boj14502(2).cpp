#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
int a[8][8];
int cpy[8][8];
int visited[8][8];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int y1, x1, y2, x2, y3, x3;
vector<int> res;

void dfs(int mp[8][8], int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        if (mp[ny][nx] == 0)
        {
            mp[ny][nx] = 2;
            dfs(mp, ny, nx);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    } // origin 2차원 배열 입력받기

    // 3개 좌표 고르기

    for (int i = 0; i < n; i++)
    {
        // cout << i << "\n";
        for (int u = 0; u < n; u++)
        {
            for (int f = 0; f < m; f++)
            {
                cpy[u][f] = a[u][f];
            }
        } // copy하는 2차원 배열 생성

        for (int j = 0; j < m; j++)
        {
            if (cpy[i][j] == 0)
            {
                y1 = i;
                x1 = j;
                cpy[i][j] = 1; //새로운 벽으로 고름(1번째 좌표)
                visited[i][j] = 1;
                for (int k = i; k < n; k++)
                {
                    for (int l = 0; l < m; l++)
                    {
                        if (cpy[k][l] == 0 && visited[k][l] == 0)
                        {
                            y2 = k;
                            x2 = l;
                            cpy[k][l] = 1; //새로운 벽으로 고름(2번째 좌표)
                            visited[k][l] = 1;

                            for (int p = k; p < n; p++)
                            {
                                for (int q = 0; q < m; q++)
                                {
                                    if (cpy[p][q] == 0 && visited[p][q] == 0)
                                    {
                                        y3 = p;
                                        x3 = q;
                                        cpy[p][q] = 1;

                                        // bfs함수 실행
                                        for (int b = 0; b < n; b++)
                                        {
                                            for (int c = 0; c < m; c++)
                                            {
                                                if (cpy[b][c] == 2)
                                                    dfs(cpy, b, c);
                                            }
                                        }

                                        int cnt = 0;

                                        for (int e = 0; e < n; e++)
                                        {
                                            for (int r = 0; r < m; r++)
                                            {
                                                if (cpy[e][r] == 0)
                                                    cnt++;
                                            }
                                        }
                                        res.push_back(cnt);
                                        for (int u = 0; u < n; u++)
                                        {
                                            for (int f = 0; f < m; f++)
                                            {
                                                cpy[u][f] = a[u][f];
                                            }
                                        }
                                        cpy[y1][x1] = 1;
                                        cpy[y2][x2] = 1;
                                    }
                                }
                                if (p == n - 1)
                                {
                                    for (int u = 0; u < n; u++)
                                    {
                                        for (int f = 0; f < m; f++)
                                        {
                                            cpy[u][f] = a[u][f];
                                        }
                                    }
                                    cpy[y1][x1] = 1;
                                    visited[y2][x2] = 0;
                                }
                            }
                        }
                    }
                    if (k == n - 1)
                    {
                        for (int u = 0; u < n; u++)
                        {
                            for (int f = 0; f < m; f++)
                            {
                                cpy[u][f] = a[u][f];
                            }
                        }
                    }
                }
            }
        }
        if (i == n - 1)
        {
            cpy[y1][x1] = 0;
        }
    }
    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());

    cout << res[0] << "\n";
}
