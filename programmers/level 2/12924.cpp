#include <iostream>
using namespace std;
int n = 1, answer = 1;
int main()
{
    for (int i = 1; i < n; i++)
    {
        int sum = i;
        for (int j = i + 1; j < n; j++)
        {
            sum += j;
            if (sum == n)
                answer++;
            else if (sum > n)
                break;
        }
    }
    cout << answer;
}