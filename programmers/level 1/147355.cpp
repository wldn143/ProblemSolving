#include <string>
using namespace std;

int solution(string t, string p)
{
    int answer = 0;
    int n = p.size();

    for (int i = 0; i <= t.size() - n; i++)
        if (stoll(t.substr(i, p.size())) <= stoll(p))
            answer++;

    return answer;
}