#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n, num, a[100001], m;
stack<int> st;
vector<char> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    st.push(num);
    num++;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        while (st.top() < m)
        {
            st.push(num);
            num++;
            v.push_back('+');
        }
        if (st.top() == m)
        {
            st.pop();
            v.push_back('-');
        }
    }
    if (st.top())
        cout << "NO";

    else
        for (char c : v)
            cout << c << "\n";
}