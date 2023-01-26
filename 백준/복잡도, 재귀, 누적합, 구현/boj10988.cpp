#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string s, temp;
    cin >> s;
    temp = s;
    reverse(temp.begin(), temp.end());
    if (temp == s)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
}