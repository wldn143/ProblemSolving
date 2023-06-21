#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 987654321
using namespace std;
int a, b, c, d;
queue<pair<int, int>> q;

int visited[1001][1001];

int bfs()
{
    while (q.size())
    {
        int ca = q.front().first;
        int cb = q.front().second;
        int cc = d - ca - cb;

        if (ca == cb && ca == cc)
            return 1;

        int ny[3] = {ca, ca, cb};
        int nx[3] = {cb, cc, cc};

        for (int i = 0; i < 3; i++)
        {
            int na = ny[i];
            int nb = nx[i];

            if (na > nb)
                na -= nb, nb += nb;
            else if (na < nb)
                nb -= na, na += na;
            else
                continue;

            int nc = d - na - nb;
            int ra = min(min(na, nb), nc);
            int rb = max(max(na, nb), nc);

            if (visited[ra][rb] == 0)
            {
                visited[ra][rb] = 1;
                q.push({ra, rb});
            }
        }
        q.pop();
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c;

    if ((a + b + c) % 3)
        cout << 0;
    else
    {
        d = a + b + c;
        q.push({a, b});
        visited[a][b] = 1;
        cout << bfs();
    }
}
