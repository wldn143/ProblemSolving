#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;
    int t_y, t_m, t_d, p_y, p_m, p_d;
    t_y = stoi(today.substr(0, 4));
    t_m = stoi(today.substr(5, 7));
    t_d = stoi(today.substr(8, 10));
    int total = t_y * 336 + t_m * 28 + t_d;

    for (int i = 0; i < privacies.size(); i++)
    {

        p_y = stoi(privacies[i].substr(0, 4));
        p_m = stoi(privacies[i].substr(5, 7));
        p_d = stoi(privacies[i].substr(8, 10));

        int p_total = p_y * 336 + p_m * 28 + p_d;
        int termToDay;
        for (string t : terms)
        {
            if (t[0] == privacies[i][11])
            {
                termToDay = stoi(t.substr(2));
                break;
            }
        }

        termToDay *= 28;

        if (total - p_total >= termToDay)
            answer.push_back(i + 1);
    }

    return answer;
}