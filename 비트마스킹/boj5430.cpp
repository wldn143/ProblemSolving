#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
int t, n, r_cnt, d_cnt, back, front;
string P, s, e;
vector<int> el;
int main()
{
    cin >> t;
    while (t--)
    {
        el.clear();
        r_cnt = 0, d_cnt = 0, back = 0, front = 0;
        cin >> P >> n >> s;
        for (char c : P)
        {
            if (c == 'R')
                r_cnt++;

            if (c == 'D')
            {
                d_cnt++;
                if (r_cnt % 2) //홀수
                    back++;
                else
                    front++;
            }
        }
        if (n)
        {
            for (char c : s)
            {
                if (c == '[')
                    continue;
                if (c == ',' || c == ']')
                {
                    el.push_back(stoi(e));
                    e = "";
                }
                else
                    e += c;
            }
        }
        if (d_cnt > n)
        {
            cout << "error"
                 << "\n";
            continue;
        }
        for (int i = 0; i < back; i++)
        {
            el.pop_back();
        }
        if (front > 0)
        {
            el.erase(el.begin(), el.begin() + front);
        }
        if (r_cnt % 2)
            reverse(el.begin(), el.end());

        cout << "[";
        for (int i = 0; i < el.size(); i++)
        {
            cout << el[i];
            if (el.size() - 1 - i)
                cout << ",";
        }
        cout << "]\n";
    }
}
