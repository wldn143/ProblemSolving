#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;
    int flag = 1;

    while (s.size() && flag)
    {
        char x = s[0];
        int a = 0, b = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (x == s[i])
                a++;
            else
                b++;

            if (a == b)
            {
                s = s.substr(a + b);
                answer++;
                break;
            }

            if (i == s.size() - 1)
            {
                answer++;
                flag = 0;
            }
        }
    }
    return answer;
}