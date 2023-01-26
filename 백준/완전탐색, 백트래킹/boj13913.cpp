#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
int n, k, r, mx = 100001;
queue<int> q;
int visited[200001];
int pre[200001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    visited[n] = 1;
    q.push(n);
    while (q.size())
    {
        int here = q.front();
        q.pop();
        if (here == k)
        {
            r = visited[k];
            break;
        }
        for (int next : {here + 1, here - 1, here * 2})
        {
            if (next >= mx || next < 0 || visited[next])
                continue;
            visited[next] = visited[here] + 1;
            pre[next] = here;
            q.push(next);
        }
    }
    int idx = k;
    stack<int> s;
    while (idx != n)
    {
        s.push(idx);
        idx = pre[idx];
    }
    s.push(n);
    cout << r - 1 << "\n";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}
