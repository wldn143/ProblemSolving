#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int a[101][101];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void check(int y, int x)
{
    a[y][x] = 3;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        if (a[ny][nx] == 0)
            check(ny, nx);
    }
    return;
}

void del(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        if (a[ny][nx] == 3)
        {
            a[y][x] = 2; //공기 닿은 치즈로 바꾸기
            break;
        }
    }
    return;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    int past = 0;
    while (1)
    {
        int cheese = 0;
        //공기 영역 설정
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 1)
                    cheese++;
            }
        }
        check(0, 0);

        if (cheese)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (a[i][j] == 1)
                    {
                        del(i, j);
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (a[i][j] == 2 || a[i][j] == 3)
                        a[i][j] = 0;
                }
            }
            past = cheese;
        }
        else
        {
            cout << cnt << "\n";
            cout << past << "\n";
            break;
        }
        cnt++;
    }
}
