#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, l, res, flag, cur, nxt;
int a[101][101], b[101][101];
int put[101][101];

void go(int m[101][101])
{
    for (int i = 0; i < n; i++)
    {
        fill(&put[0][0], &put[0][0] + 101 * 101, 0);
        flag = 1;
        for (int j = 0; j < n - 1; j++)
        {
            if (m[i][j] != m[i][j + 1])
            {
                cur = m[i][j];
                nxt = m[i][j + 1];
                if (abs(nxt - cur) == 1)
                {
                    if (cur > nxt)
                    {
                        for (int k = 1; k <= l; k++)
                        {
                            if (j + k >= n || m[i][j + k] != nxt)
                            {
                                flag = 0;
                                break;
                            }
                            put[i][j + k] = 1;
                        }
                    }
                    else
                    {
                        for (int k = 0; k < l; k++)
                        {
                            if (put[i][j - k] || j - k < 0 || m[i][j - k] != cur)
                            {
                                flag = 0;
                                break;
                            }
                            put[i][j - k] = 1;
                        }
                    }
                    if (!flag)
                        break;
                    continue;
                }
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            res++;
        }
    }
}

int main()
{
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            b[j][i] = a[i][j]; //대박...!!
        }
    }
    go(a);
    go(b);
    cout << res << "\n";
}
