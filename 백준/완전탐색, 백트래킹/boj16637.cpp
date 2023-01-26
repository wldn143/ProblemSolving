#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int n;
string s;
vector<int> first;
vector<int> perm;
queue<int> num;
queue<char> math;
int mx = -2147483648;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> s;
    if (n == 1)
        cout << s << "\n";
    else
    {
        for (int i = 0; i < n - 1; i += 2)
        {
            char cul = s[i + 1];
            if (cul == '+')
            {
                first.push_back((s[i] - '0') + (s[i + 2] - '0'));
            }
            else if (cul == '*')
            {
                first.push_back((s[i] - '0') * (s[i + 2] - '0'));
            }
            else
            {
                first.push_back((s[i] - '0') - (s[i + 2] - '0'));
            }
        }
        int l = first.size() / 2;

        for (int i = 0; i <= l; i++) // l==2 1이 될수있는건 최대 2
        {
            int k = first.size() - i; // 0의 개수
            while (k--)
            {
                perm.push_back(0);
            }
            int j = i;
            while (j--)
            {
                perm.push_back(1);
            }
            do
            {
                int cnt = 0;
                for (int i = 0; i < perm.size() - 1; i++)
                {
                    if (perm[i] && perm[i + 1])
                        cnt++;
                }
                if (!cnt)
                {
                    int flag = 0;

                    for (int i = 0; i < perm.size(); i++)
                    {
                        if (!perm[i])
                        {
                            if (flag)
                            {
                                int j = i * 2 + 1;
                                math.push(s[j]);
                            }
                            else
                            {
                                int j = i * 2; //계산식에서 인덱스
                                num.push(s[j] - '0');
                                math.push(s[j + 1]);
                            }
                            flag = 0;
                        }
                        else
                        {
                            num.push(first[i]);
                            flag = 1;
                        }
                        if (i == perm.size() - 1 && perm[i] == 0)
                        {
                            num.push(s[n - 1] - '0');
                        }
                    }
                    int result = num.front();
                    num.pop();
                    while (num.size() || math.size())
                    {
                        if (math.size())
                        {
                            char c = math.front();
                            if (c == '+')
                            {
                                result += num.front();
                                num.pop();
                            }
                            else if (c == '*')
                            {
                                result *= num.front();
                                num.pop();
                            }
                            else if (c == '-')
                            {
                                result -= num.front();
                                num.pop();
                            }
                            math.pop();
                        }
                    }
                    mx = max(mx, result);
                }
            } while (next_permutation(perm.begin(), perm.end()));
            perm.clear();
        }
        cout << mx << "\n";
    }
}
