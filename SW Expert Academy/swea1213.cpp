#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, res;
string s1, s2;
int main()
{
    for (int t = 1; t <= 10; t++)
    {
        cin >> n;
        cin >> s1 >> s2;
        res = 0;
        for (int i = 0; i < s2.size(); i++)
        {
            if (s2[i] == s1[0])
            {
                for (int j = 1; j < s1.size(); j++)
                {
                    if (s2[i + j] != s1[j])
                        break;
                    else if (j == s1.size() - 1)
                        res++;
                }
            }
        }
        cout << "#" << t << " " << res << "\n";
    }
    return 0;
}