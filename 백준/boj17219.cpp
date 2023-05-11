#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int n, m;
string address, password;
map<string, string> memo;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    while (n--)
    {
        cin >> address >> password;
        memo.insert({address, password});
    }
    while (m--)
    {
        cin >> address;
        auto a = memo.find(address);
        cout << a->second << "\n";
    }
}