#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int n, a, node, nextY, nextX;
queue<int> input;
int visited[1025][1025];
int map[1025][1025];
void dfs(int y, int x)
{
    if (y == n)
    {
        visited[y][x] = 1;
        nextY = y, nextX = x;
        while (1)
        {
            nextY -= 1;
            nextX /= 2;
            if (nextY == 0)
            {
                map[y][x] = input.front();
                input.pop();
                break;
            }
            if (nextY > 0 && visited[nextY][nextX] == 0)
            {
                map[y][x] = input.front();
                input.pop();
                dfs(nextY, nextX);
                break;
            }
        }
    }
    else if (visited[y + 1][x * 2] == 0)
    {
        dfs(y + 1, x * 2);
    }
    else if (visited[y + 1][x * 2 + 1] == 0)
    {
        visited[y][x] = 1;
        map[y][x] = input.front();
        input.pop();
        dfs(y + 1, x * 2 + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    node = pow(2, n) - 1;
    for (int i = 0; i < node; i++)
    {
        cin >> a;
        input.push(a);
    }

    visited[n][0] = 1;
    dfs(n, 0);

    for (int i = 0; i < n; i++)
    {
        node = pow(2, i);
        for (int j = 0; j < node; j++)
        {
            cout << map[i + 1][j] << " ";
        }
        cout << "\n";
    }
}
