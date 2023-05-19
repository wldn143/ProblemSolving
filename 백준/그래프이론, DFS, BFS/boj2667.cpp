#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, x, arr[26][26], visited[26][26], cnt, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
vector<int> result;

void dfs(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n)
            continue;

        if (!visited[ny][nx] && arr[ny][nx])
        {
            visited[ny][nx] = 1;
            cnt++;
            dfs(ny, nx);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%1d", &arr[i][j]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && arr[i][j])
            {
                visited[i][j] = 1;
                cnt++;
                dfs(i, j);
                result.push_back(cnt);
                cnt = 0;
            }
        }
    }

    cout << result.size() << "\n";
    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << "\n";
}