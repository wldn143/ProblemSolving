#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int cnt[26] = {
    0,
};
int main()
{
    string s;
    cin >> s;

    for (char a : s)
    { // s안에 있는 문자 a들을 순회할거라는 뜻
        cnt[a - 'a']++;
    }

    for (int i : cnt)
    {
        cout << i << " ";
    }
}