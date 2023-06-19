#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, k, idx;
priority_queue<int, vector<int>, greater<int>> minheap;
priority_queue<int> maxheap;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    while (n--)
    {
        cin >> k;
        if (maxheap.size() == minheap.size())
            maxheap.push(k);
        else
            minheap.push(k);
        if (maxheap.size() && minheap.size() && maxheap.top() > minheap.top())
        {
            int a = maxheap.top();
            int b = minheap.top();
            maxheap.pop();
            minheap.pop();
            maxheap.push(b);
            minheap.push(a);
        }
        cout << maxheap.top() << "\n";
    }
}
