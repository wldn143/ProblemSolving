#include <iostream>
#include <algorithm>
using namespace std;
int n, mn = 987654321;
void div_2(int a, int cnt);
void div_3(int a, int cnt);
void mi(int a, int cnt);

void div_2(int a, int cnt)
{
    if (a < 1)
        return;
    if (a == 1)
    {
        mn = min(mn, cnt);
        return;
    }
    if (a % 2 == 0)
        div_2(a / 2, cnt + 1);
    if (a % 3 == 0)
        div_3(a / 3, cnt + 1);
    mi(a - 1, cnt + 1);
}
void div_3(int a, int cnt)
{
    if (a < 1)
        return;
    if (a == 1)
    {
        mn = min(mn, cnt);
        return;
    }

    if (a % 2 == 0)
        div_2(a / 2, cnt + 1);
    if (a % 3 == 0)
        div_3(a / 3, cnt + 1);
    mi(a - 1, cnt + 1);
}
void mi(int a, int cnt)
{
    if (a < 1)
        return;
    if (a == 1)
    {
        mn = min(mn, cnt);
        return;
    }
    if (a % 2 == 0)
        div_2(a / 2, cnt + 1);
    if (a % 3 == 0)
        div_3(a / 3, cnt + 1);
    mi(a - 1, cnt + 1);
}
int main()
{
    cin >> n;

    if (n % 2 == 0)
        div_2(n / 2, 1);
    if (n % 3 == 0)
        div_2(n / 3, 1);
    mi(n - 1, 1);
    cout << mn << "\n";
    return 0;
}