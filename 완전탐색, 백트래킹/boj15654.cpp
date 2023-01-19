#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, a, visited[9], arr[9];
vector<int> c;

void go(int idx)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        visited[i] = 1;
        arr[idx] = c[i];
        go(idx + 1);
        visited[i] = 0;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        c.push_back(a);
    }

    sort(c.begin(), c.end());
    go(0);
}