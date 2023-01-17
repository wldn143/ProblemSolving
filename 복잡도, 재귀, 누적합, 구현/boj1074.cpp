#include <iostream>
using namespace std;
int n, r, c, ret;

void go(int y, int x, int size)
{
    if ((y == r) && (x == c))
    {
        cout << ret << "\n";
        return;
    }
    if ((y <= r && r < y + size) && (x <= c && c < x + size))
    {
        go(y, x, size / 2);
        go(y, x + size / 2, size / 2);
        go(y + size / 2, x, size / 2);
        go(y + size / 2, x + size / 2, size / 2);
    }
    else
    {
        ret += size * size;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> r >> c;
    go(0, 0, (1 << n));
}