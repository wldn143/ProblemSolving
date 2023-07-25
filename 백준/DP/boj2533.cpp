#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
int n, a, b;
bool visited[1000001];
int dp[1000001][2];
vector<int> node[1000001];
void find(int x)
{
    visited[x] = 1;
    dp[x][1] = 1;
    for (int i = 0; i < node[x].size(); i++)
    {
        int child = node[x][i];
        if (visited[child])
            continue;
        find(child);
        dp[x][0] += dp[child][1];
        dp[x][1] += min(dp[child][1], dp[child][0]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    find(1);
    cout << min(dp[1][0], dp[1][1]);
}