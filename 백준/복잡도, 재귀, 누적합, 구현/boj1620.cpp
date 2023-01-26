#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>

using namespace std;
int n, m;
string s, x;
map<string, int> p;
map<int, string> p2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        p[s] = i;
        p2[i] = s;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (atoi(s.c_str()) == 0)
        { //문자면
            cout << p[s] << "\n";
        }
        else //숫자면
            cout << p2[atoi(s.c_str())] << "\n";
    }
}