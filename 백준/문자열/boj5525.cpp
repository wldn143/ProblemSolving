#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, m, idx, result;
string s;

void check(int i, int cnt)
{
    if (s[i + 1] == 'O' && s[i + 2] == 'I')
        check(i + 2, cnt + 1);
    else
    {
        if (cnt >= n)
            result += cnt - n + 1;
        idx = i;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> s;

    for (idx = 0; idx < s.size(); idx++)
    {
        if (s[idx] == 'I')
            check(idx, 0);
    }
    cout << result;
}