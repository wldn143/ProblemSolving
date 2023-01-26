#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, cnt;
vector<int> hol;
bool prime[4000001];

int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
            continue;
        for (int j = 2 * i; j <= n; j += i)
        {
            prime[j] = 1;
        }
    }
    for (int i = n; i > 1; i--)
    {
        if (!prime[i])
            hol.push_back(i);
    }

    for (int i = 0; i < hol.size(); i++)
    {
        int next = n;
        if (next == hol[i])
        {
            cnt++;
            continue;
        }
        if (next - hol[i] >= hol[i + 1])
        {
            int j = i;
            while (j < hol.size())
            {
                if (next == hol[j])
                {
                    cnt++;
                    break;
                }
                if (next - hol[j] < hol[j + 1])
                    break;
                next -= hol[j];
                j++;
            }
        }
    }
    cout << cnt << "\n";
}
