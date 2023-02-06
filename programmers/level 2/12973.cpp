#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<char> st;
int solution(string s)
{
    int answer = -1;
    st.push(s[0]);
    for (int i = 1; i < s.size(); i++)
    {
        if (st.size() && s[i] == st.top())
            st.pop();
        else
            st.push(s[i]);
    }
    if (st.empty())
        answer = 1;
    else
        answer = 0;
    return answer;
}