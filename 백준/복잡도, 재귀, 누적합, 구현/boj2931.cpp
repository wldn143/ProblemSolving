#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int r, c;
char map[26][26];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int open[4];
vector<pair<int, int>> m;
queue<pair<pair<int, int>, int>> q;
int ry, rx;

int check_limit(int y, int x)
{
    if (y <= 0 || x <= 0 || y > r || x > c)
        return 0;
    return 1;
}

void find_pipe()
{
    for (int i = 0; i < 4; i++)
    {
        int ny = ry + dy[i];
        int nx = rx + dx[i];
        char c = map[ny][nx];
        if (check_limit(ny, nx) == 0)
            continue;
        if (i == 0)
        {
            if (c == '-' || c == '+' || c == '3' || c == '4')
                open[0] = 1;
        }
        if (i == 1)
        {
            if (c == '-' || c == '+' || c == '1' || c == '2')
                open[1] = 1;
        }
        if (i == 2)
        {
            if (c == '|' || c == '+' || c == '2' || c == '3')
                open[2] = 1;
        }
        if (i == 3)
        {
            if (c == '|' || c == '+' || c == '1' || c == '4')
                open[3] = 1;
        }
    }
    cout << ry << " " << rx << " ";

    if (open[0] && open[1] && open[2] && open[3])
        cout << "+";
    else
    {
        if (open[0] && open[1])
            cout << "-";
        if (open[2] && open[3])
            cout << "|";
        if (open[0] && open[2])
            cout << "1";
        if (open[0] && open[3])
            cout << "2";
        if (open[1] && open[3])
            cout << "3";
        if (open[1] && open[2])
            cout << "4";
    }
}
void check_dir(int y, int x)
{
    int d;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        char c = map[ny][nx];
        if (c == '.' || check_limit(ny, nx) == 0)
            continue;

        if (i == 0)
        {
            if (c == '-' || c == '+')
                d = 0;
            if (c == '3')
                d = 3;
            if (c == '4')
                d = 2;
        }
        if (i == 1)
        {
            if (c == '-' || c == '+')
                d = 1;
            if (c == '1')
                d = 2;
            if (c == '2')
                d = 3;
        }
        if (i == 2)
        {
            if (c == '|' || c == '+')
                d = 2;
            if (c == '2')
                d = 0;
            if (c == '3')
                d = 1;
        }
        if (i == 3)
        {
            if (c == '|' || c == '+')
                d = 3;
            if (c == '4')
                d = 1;
            if (c == '1')
                d = 0;
        }
        q.push({{ny, nx}, d});
    }
    return;
}

void search()
{
    int y = q.front().first.first;
    int x = q.front().first.second;
    check_dir(y, x);
    q.pop();

    while (q.size())
    {
        y = q.front().first.first;
        x = q.front().first.second;
        int d = q.front().second;
        int ny = y + dy[d];
        int nx = x + dx[d];
        int nd;
        char c = map[ny][nx];

        if (c == '.')
        {
            ry = ny;
            rx = nx;
            return;
        }

        if (d == 0)
        {
            if (c == '-' || c == '+')
                nd = 0;
            if (c == '3')
                nd = 3;
            if (c == '4')
                nd = 2;
        }
        if (d == 1)
        {
            if (c == '-' || c == '+')
                nd = 1;
            if (c == '1')
                nd = 2;
            if (c == '2')
                nd = 3;
        }
        if (d == 2)
        {
            if (c == '|' || c == '+')
                nd = 2;
            if (c == '2')
                nd = 0;
            if (c == '3')
                nd = 1;
        }
        if (d == 3)
        {
            if (c == '|' || c == '+')
                nd = 3;
            if (c == '4')
                nd = 1;
            if (c == '1')
                nd = 0;
        }
        q.push({{ny, nx}, nd});
        q.pop();
    }
}

int main()
{
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            scanf("%1s", &map[i][j]);
            if (map[i][j] == 'M' || map[i][j] == 'Z')
                m.push_back({i, j});
        }
    }

    int y1 = m[0].first;
    int x1 = m[0].second;
    int y2 = m[1].first;
    int x2 = m[1].second;

    q.push({{y1, x1}, -1});
    search();
    find_pipe();
}
