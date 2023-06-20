#include <iostream>
#include <algorithm>
#define MAX 987654321
using namespace std;
int n, m, a, b, c, ret = MAX;
int edge[401][401];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            edge[i][j] = MAX;

    while (m--)
    {
        cin >> a >> b >> c;
        edge[a][b] = c;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
                if (i == j)
                    ret = min(ret, edge[i][j]);
            }
        }
    }

    if (ret == MAX)
        cout << -1;
    else
        cout << ret;
}
