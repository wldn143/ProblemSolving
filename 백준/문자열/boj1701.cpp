#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string n;
int mx;
int p[5000];
void fail(string s)
{
    int j = 0;
    for (int i = 0; i < s.size(); i++)
        p[i] = 0;
    for (int i = 1; i < s.size(); i++)
    {
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
        {
            p[i] = ++j;
            mx = max(mx, p[i]);
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n.size(); i++)
        fail(n.substr(i));
    cout << mx;
}