#include <iostream>
using namespace std;
int n, cnt;

void stick(int x, int cur)
{
    if (x == 0)
        return;

    if (cur > x)
    {
        stick(x, cur / 2);
    }
    else if (cur <= x)
    {
        cnt++;
        stick(x - cur, cur);
    }
}

int main()
{
    cin >> n;
    stick(n, 64);
    cout << cnt;
}
