#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int n, k;
set<string> st;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while (n--)
    {
        cin >> k;
        string str = "";
        string tmp;
        for (int i = 0; i < k; i++)
        {
            cin >> tmp;
            str += ("*" + tmp);
            st.insert(str);
        }
    }

    for (string s : st)
    {
        int pos = s.find_last_of("*");
        int cnt = count(s.begin(), s.end(), '*');
        for (int i = 0; i < cnt - 1; i++)
            cout << "--";
        cout << s.substr(pos + 1) << "\n";
    }
}
