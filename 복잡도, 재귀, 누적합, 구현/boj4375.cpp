#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int n;
//숫자 커지는거 막아야함...
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n)
    {
        int a = 1;
        int cnt = 1;
        while (1)
        {
            if (a % n == 0)
            {
                cout << cnt << "\n";
                break;
            }
            a = a * 10 + 1;
            a %= n;
            cnt++;
        }
    }
}