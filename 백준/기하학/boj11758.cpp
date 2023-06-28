#include <iostream>
#include <algorithm>
using namespace std;
int x1, x2, x3;
int y1, y2, y3;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int ret = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    if (ret < 0)
        cout << -1;
    else if (ret == 0)
        cout << 0;
    else
        cout << 1;
}
