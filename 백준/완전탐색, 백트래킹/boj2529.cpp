#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int n, a;
char c;
vector<char> v;
int up[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int down[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        v.push_back(c);
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i] == '>')
        {
            for (int j = 0; j <= n; j++)
            {
                if (down[j] != -1)
                {
                    cout << down[j];
                    down[j] = -1;
                    break;
                }
            }
        }

        else if (v[i] == '<')
        {
            int cnt2 = 1;
            while (1)
            {
                if (v[i + 1] == '<')
                {
                    cnt2++; //부등호 개수
                    i++;
                }

                else
                    break;
            }
            for (int j = 0; j <= n; j++)
            {
                if (down[j] != -1)
                {
                    for (int k = j + cnt2; k > j; k--)
                    {
                        cout << down[k];
                        down[k] = -1;
                    }
                    break;
                }
            }
        }
    }

    for (int l = 0; l <= n; l++)
    {
        if (down[l] != -1)
            cout << down[l] << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i] == '<')
        {
            for (int j = 0; j <= n; j++)
            {
                if (up[j] != -1)
                {
                    cout << up[j];
                    up[j] = -1;
                    break;
                }
            }
        }

        else if (v[i] == '>')
        {
            int cnt = 1;
            while (1)
            {
                if (v[i + 1] == '>')
                {
                    cnt++; //부등호 개수
                    i++;
                }

                else
                    break;
            }
            for (int j = 0; j <= n; j++)
            {
                if (up[j] != -1)
                {
                    for (int k = j + cnt; k > j; k--)
                    {
                        cout << up[k];
                        up[k] = -1;
                    }
                    break;
                }
            }
        }
    }

    for (int l = 0; l <= n; l++)
    {
        if (up[l] != -1)
            cout << up[l] << "\n";
    }
}
