#include <string>
#include <algorithm>
using namespace std;

string solution(string s)
{
    string answer = "", tmp = "";
    int a, mn = 987654321, mx = -987654321;

    for (int i = 0; i <= s.size(); i++)
    {
        if (s[i] == ' ' || i == s.size())
        {
            if (tmp[0] == '-')
                a = stoi(tmp.substr(1)) * -1;
            else
                a = stoi(tmp);
            mn = min(mn, a);
            mx = max(mx, a);
            tmp = "";
        }
        else
            tmp += s[i];
    }
    answer += to_string(mn) + " " + to_string(mx);
    return answer;
}