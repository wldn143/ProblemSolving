#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int n, node;
int a[1025];
vector<int> tree[14];
void go(int s, int e, int level)
{
    if (s > e)
        return;
    if (s == e)
    {
        tree[level].push_back(a[s]);
        return;
    }
    int mid = (s + e) / 2;
    tree[level].push_back(a[mid]);
    go(s, mid - 1, level + 1);
    go(mid + 1, e, level + 1);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    node = pow(2, n) - 1;
    for (int i = 0; i < node; i++)
    {
        cin >> a[i];
    }
    go(0, node, 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j : tree[i])
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}
