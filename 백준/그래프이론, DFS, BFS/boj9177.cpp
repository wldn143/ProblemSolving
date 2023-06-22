#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#define MAX 987654321
#define ll long long
using namespace std;
int T;
int visited[201][201];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        string a, b, c;
        cin >> a >> b >> c;
        memset(visited, 0, sizeof(visited));
        queue<pair<int, int>> q;

        q.push({0, 0});
        visited[0][0] = 1;
        int flag = 0;
        while (q.size())
        {
            int i = q.front().first;
            int j = q.front().second;
            int k = i + j;

            if (i == a.length() && j == b.length()) // c도 같아야하니?ㅡㅡ
            {
                flag = 1;
                break;
            }

            if (i != a.length() && a[i] == c[k] && !visited[i + 1][j])
            {
                visited[i + 1][j] = 1;
                q.push({i + 1, j});
            }

            if (j != b.length() && b[j] == c[k] && !visited[i][j + 1])
            {
                visited[i][j + 1] = 1;
                q.push({i, j + 1});
            }
            q.pop();
        }
        cout << "Data set " << t << ": " << (flag ? "yes" : "no") << '\n';
    }
}
