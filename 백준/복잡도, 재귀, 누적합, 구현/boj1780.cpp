#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int n, mp[2188][2188];
map<int, int> result;
void paper(int y, int x, int r)
{

    int first = mp[y][x];
    int flag = 0;

    for (int i = y; i < y + r; i++)
    {
        for (int j = x; j < x + r; j++)
        {
            if (mp[i][j] != first)
            {
                i = y + r;
                flag = 1;
                break;
            }
        }
    }
    if (flag)
    {
        paper(y, x, r / 3);
        paper(y, x + r / 3, r / 3);
        paper(y, x + r / 3 + r / 3, r / 3);
        paper(y + r / 3, x, r / 3);
        paper(y + r / 3, x + r / 3, r / 3);
        paper(y + r / 3, x + r / 3 + r / 3, r / 3);
        paper(y + r / 3 + r / 3, x, r / 3);
        paper(y + r / 3 + r / 3, x + r / 3, r / 3);
        paper(y + r / 3 + r / 3, x + r / 3 + r / 3, r / 3);
    }
    else
    {
        result[first]++;
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mp[i][j];

    paper(0, 0, n);
    cout << result[-1] << "\n";
    cout << result[0] << "\n";
    cout << result[1] << "\n";
}