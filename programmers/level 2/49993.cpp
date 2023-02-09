#include <string>
#include <vector>
#include <stack>
using namespace std;

int alp[26];

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    stack<char> st;

    for (int i = 0; i < skill.length(); i++)
        alp[skill[i] - 'A'] = 1;

    for (int i = 0; i < skill_trees.size(); i++)
    {
        stack<char> st;

        for (int j = skill_trees[i].size() - 1; j >= 0; j--)
            if (alp[skill_trees[i][j] - 'A'])
                st.push(skill_trees[i][j]);

        for (int j = 0; j < skill.size(); j++)
        {
            if (st.size() && skill[j] == st.top())
                st.pop();
            else
                break;
        }
        if (st.empty())
            answer++;
    }

    return answer;
}