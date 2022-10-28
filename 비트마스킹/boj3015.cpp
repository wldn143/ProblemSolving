#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
ll n, ret, now, cnt;
stack<pair<ll, ll>> s;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> now;
        if (s.empty())
        {
            s.push({now, 0});
            continue;
        }

        if (s.top().first < now) // pop진행
        {
            while (!s.empty() && s.top().first < now)
            { // top이 now보다 크거나 같아지면 끝남
                ret++;
                s.pop();
                if (s.empty())
                    break;
            }
        }

        if (!s.empty() && s.top().first == now)
        {
            cnt = s.top().second + 1;
            s.push({now, cnt});
            ret += cnt;
            continue;
        }

        if (!s.empty() && s.top().first > now)
        {
            ret++;
            s.push({now, 1});
            continue;
        }
        s.push({now, 0});
    }
    cout << ret << "\n";
}
