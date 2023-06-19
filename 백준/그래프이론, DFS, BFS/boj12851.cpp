#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, k, sec, sum;
int visited[100001];
queue<pair<int, int>> q;

int main()
{
    cin >> n >> k;
    q.push({n, 0});
    while (q.size())
    {
        int now = q.front().first;
        int time = q.front().second;

        visited[now] = 1;

        if (!sum && now == k)
        { // 처음 도착
            sum++;
            sec = time;
        }

        else if (sum && now == k && time == sec)
            sum++;

        if (now + 1 <= 100000 && !visited[now + 1])
            q.push({now + 1, time + 1});
        if (now * 2 <= 100000 && !visited[now * 2])
            q.push({now * 2, time + 1});
        if (now - 1 >= 0 && !visited[now - 1])
            q.push({now - 1, time + 1});
        q.pop();
    }

    cout << sec << "\n"
         << sum;
}
