#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t, n, a, b;
int parent[10001];
vector<int> tmp, a_parent, b_parent;

int find_parent(int node)
{
    tmp.push_back(node);
    if (parent[node] == node)
        return 0;
    return find_parent(parent[node]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;

    while (t--)
    {
        fill_n(parent, 10001, 0);

        cin >> n;
        for (int i = 1; i < n; i++)
        {
            cin >> a >> b;
            parent[b] = a;
        }

        for (int i = 1; i <= n; i++)
        {
            if (!parent[i])
            {
                parent[i] = i;
                break;
            }
        }

        cin >> a >> b;

        find_parent(a);
        a_parent = tmp;
        tmp.clear();
        find_parent(b);
        b_parent = tmp;
        tmp.clear();

        int ret = 0;

        for (int i = 0; i < a_parent.size(); i++)
        {
            int k = a_parent.size() - 1 - i;
            int l = b_parent.size() - 1 - i;
            if (a_parent[k] == b_parent[l])
                ret = b_parent[l];
            else
                break;
        }
        cout << ret << "\n";
    }
}
