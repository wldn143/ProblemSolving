#include <algorithm>
#include <vector>
using namespace std;
int ret;

int solution(vector<int> people, int limit)
{
    sort(people.begin(), people.end(), greater<>());

    int n = people.size();
    for (int i = 0, j = n - 1; i <= j; i++)
    {
        if (people[i] + people[j] <= limit)
            j--;
        ret++;
    }
    return ret;
}