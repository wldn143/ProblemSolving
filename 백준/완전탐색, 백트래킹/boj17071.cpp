#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
int n, k, flag, idx, mx = 500001;
queue<int> q;
int visited[500001];
int visited2[500001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    int dong = k;
    visited[n] = 1;
    visited2[n] = 1;
    int level = visited2[n]; // 1
    q.push(n);
    while (q.size())
    {
        int here = q.front();
        if (here == k)
        {
            flag = 1;
            // break;
        }

        if (visited2[here] != level) //레벨이 달라지면
        {
            // cout << "here: " << here << " visited2[here]: " << visited2[here] << " level: " << level << " idx: " << idx << "\n";
            fill(&visited[0], &visited[0] + 500001, 0); //초기화
                                                        //  idx++;
                                                        // visited[here] = 1;
            level = visited2[here];                     //레벨은 이전레벨이야
            //  k += idx;
        }
        // cout << "here: " << here << " visited2[here]: " << visited2[here] << " idx: " << idx << "\n";
        if (here == 6)
            break;
        q.pop();
        // cout << "here: " << here << " visited2[here]: " << visited2[here] << " k: " << k << " idx: " << idx << "\n";

        // int vis = k;
        // for (int i = 1; i <= visited2[here] - 1; i++)
        // {
        //     vis += i;
        // }

        for (int next : {here + 1, here - 1, here * 2})
        {
            if (next >= mx || next < 0 || visited[next])
                continue;
            cout << "here: " << here << " next: " << next << " visited[next]: " << visited[next] << "\n";
            visited[next] = 1;
            visited2[next] = visited2[here] + 1;
            cout << "visited2[next]: " << visited2[next] << "\n";
            q.push(next);
        }
    }
    // if (!flag)
    //     cout << "-1\n";
}
