#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int n, k, cnt, res, ten, w[50], mx = -1;
string s;
set<int> tmp;
vector<int> comp;
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        s = s.substr(4, s.length() - 8);
        for (char str : s)
        {
            if (str != 'a' && str != 'n' && str != 't' && str != 'i' && str != 'c')
            {
                w[i] |= (1 << (str - 'a'));
                tmp.insert(1 << (str - 'a'));
            }
        }
    }
    vector<int> comp(tmp.size());
    copy(tmp.begin(), tmp.end(), comp.begin());

    if (k < 5)
    {
        cout << 0 << "\n";
        return 0;
    }
    if (k == 5)
    {
        for (int i = 0; i < n; i++)
        {
            if (w[i] == 0)
                res++;
        }
        cout << res << "\n";
        return 0;
    }
    k -= 5;

    if (k > comp.size())
        k = comp.size();

    for (int i = 1; i < (1 << comp.size()); i++)
    {
        cnt = 0, ten = 0, res = 0;
        for (int j = 0; j < comp.size(); j++)
        {
            if (i & (1 << j))
            {
                cnt++;
                ten += comp[j];
            }
        }
        if (cnt == k)
        {
            for (int j = 0; j < n; j++)
            {
                for (int l = 0; l < 26; l++)
                {
                    int t = ten & (1 << l);
                    int o = w[j] & (1 << l);
                    if (!t && o)
                        break;
                    else if (l == 26)
                    {
                        res++;
                    }
                }
            }
            mx = max(mx, res);
        }
    }
    cout << mx << "\n";
}
