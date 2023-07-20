#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int r, c;
char map[26][26];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int open[4];
vector<pair<int, int>> m;
queue<pair<pair<int, int>, int>> q;
int ry, rx;

bool isValid(int y, int x)
{
    return (y >= 1 && y <= r) && (x >= 1 && x <= c);
}

void find_pipe()
{
    for (int i = 0; i < 4; i++)
    {
        int ny = ry + dir[i][0];
        int nx = rx + dir[i][1];
        char c = map[ny][nx];
        if (i == 0)
        {
            if (c == '|' || c == '+' || c == '2' || c == '3')
                open[0] = 1;
        }
        if (i == 1)
        {
            if (c == '-' || c == '+' || c == '3' || c == '4')
                open[1] = 1;
        }
        if (i == 2)
        {
            if (c == '|' || c == '+' || c == '1' || c == '4')
                open[2] = 1;
        }
        if (i == 3)
        {
            if (c == '-' || c == '+' || c == '1' || c == '2')
                open[3] = 1;
        }
    }
    cout << ry << " " << rx << " ";

    if (open[0] && open[1] && open[2] && open[3])
    {
        cout << "+";
    }
    else if (open[0] && !open[1] && open[2] && !open[3])
    {
        cout << "|";
    }
    else if (!open[0] && open[1] && !open[2] && open[3])
    {
        cout << "-";
    }
    else if (open[0] && open[1] && !open[2] && !open[3])
    {
        cout << "1";
    }
    else if (!open[0] && open[1] && open[2] && !open[3])
    {
        cout << "2";
    }
    else if (!open[0] && !open[1] && open[2] && open[3])
    {
        cout << "3";
    }
    else if (open[0] && !open[1] && !open[2] && open[3])
    {
        cout << "4";
    }
}
int check_dir(int y, int x)
{
    int d = -1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];

        char c = map[ny][nx];
        if (c == '.')
            continue;
        if (!isValid(ny, nx))
            continue;

        if (i == 0)
        {
            if (c == '|' || c == '+' || c == '2' || c == '3')
                d = 0;
        }
        else if (i == 1)
        {
            if (c == '-' || c == '+' || c == '3' || c == '4')
                d = 1;
        }
        else if (i == 2)
        {
            if (c == '|' || c == '+' || c == '1' || c == '4')
                d = 2;
        }
        else if (i == 3)
        {
            if (c == '-' || c == '+' || c == '1' || c == '2')
                d = 3;
        }
    }
    return d;
}

void search()
{
    int y = m[0].first;
    int x = m[0].second;
    int d = check_dir(y, x);

    if (d == -1)
    {
        y = m[1].first;
        x = m[1].second;
        d = check_dir(y, x);
    }
    q.push({{y, x}, d});

    while (q.size())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int d = q.front().second;
        int ny = y + dir[d][0];
        int nx = x + dir[d][1];
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
            if (c == '|' || c == '+')
                nd = 0;
            else if (c == '2')
                nd = 1;
            else if (c == '3')
                nd = 3;
        }
        else if (d == 1)
        {
            if (c == '-' || c == '+')
                nd = 1;
            else if (c == '3')
                nd = 2;
            else if (c == '4')
                nd = 0;
        }
        else if (d == 2)
        {
            if (c == '|' || c == '+')
                nd = 2;
            else if (c == '1')
                nd = 1;
            else if (c == '4')
                nd = 3;
        }
        else if (d == 3)
        {
            if (c == '-' || c == '+')
                nd = 3;
            else if (c == '1')
                nd = 0;
            else if (c == '2')
                nd = 2;
        }
        q.push({{ny, nx}, nd});
        q.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;

    char s;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> s;
            map[i][j] = s;
            if (map[i][j] == 'M' || map[i][j] == 'Z')
                m.push_back({i, j});
        }
    }

    search();
    find_pipe();
}
