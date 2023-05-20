#include <iostream>
#include <algorithm>
using namespace std;
int n, cnt, cnt2;
string s;
char arr[101][101], arr2[101][101];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};
int origin[101][101], rgb[101][101];

void DFS(int y, int x, int cnt)
{
    char start = arr[y][x];
    origin[y][x] = cnt;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n || origin[ny][nx])
            continue;

        if (start == arr[ny][nx])
            DFS(ny, nx, cnt);
    }
    return;
}

void DFS2(int y, int x, int cnt)
{
    char start = arr2[y][x];
    rgb[y][x] = cnt;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n || rgb[ny][nx])
            continue;

        if (start == arr2[ny][nx])
            DFS2(ny, nx, cnt);
    }
    return;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = s[j];
            if (s[j] == 'R' || s[j] == 'G')
                arr2[i][j] = 'R';
            else
                arr2[i][j] = 'B';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!origin[i][j])
            {
                cnt++;
                DFS(i, j, cnt);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!rgb[i][j])
            {
                cnt2++;
                DFS2(i, j, cnt2);
            }
        }
    }

    cout << cnt << " " << cnt2;
}