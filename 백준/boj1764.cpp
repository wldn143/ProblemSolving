#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n, m;
string str;
vector<string> res;
map<string, int> mp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n + m; i++)
    {
        cin >> str;
        mp[str]++;
        if (mp[str] == 2)
            res.push_back(str);
    }
    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << "\n";
}