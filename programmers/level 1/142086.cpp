#include <string>
#include <vector>
#include <string.h>
using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    int arr[26];
    memset(arr, -1, sizeof(arr));

    for (int i = 0; i < s.size(); i++)
    {
        int idx = s[i] - 'a';
        if (arr[idx] == -1)
            answer.push_back(-1);
        else
            answer.push_back(i - arr[idx]);
        arr[idx] = i;
    }

    return answer;
}