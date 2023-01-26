#include <iostream>
#include <algorithm>
using namespace std;
char s1[1001], s2[1001];
int dp[1001][1001], i, j;
int main()
{
    scanf("%s %s", s1 + 1, s2 + 1);
    for (i = 1; s1[i]; i++)
    {
        for (j = 1; s2[j]; j++)
        {
            dp[i][j] = max({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] + (s1[i] == s2[j])});
        }
    }
    cout << dp[i - 1][j - 1] << "\n";
}