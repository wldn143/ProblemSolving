#include <iostream>
using namespace std;
typedef long long ll;
ll a, b, c;
ll mul(ll a, ll b)
{
    if (b == 1)
        return a % c;
    ll ret = mul(a, b / 2);
    //재귀함수 다 호출한 이후(거꾸로 돌아갈 때)
    ret = (ret * ret) % c;
    if (b % 2)
        ret = (ret * a) % c; //홀수면 한 번 더 곱해준 뒤 나머지 연산
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;
    cout << mul(a, b) << "\n";
}