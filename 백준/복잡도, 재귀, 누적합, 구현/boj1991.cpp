#include <iostream>
#include <algorithm>
using namespace std;
int n;
int r[27], l[27];

void preorder(int node)
{
    if (node == -1)
        return;
    cout << (char)(node + 'A');
    preorder(l[node]);
    preorder(r[node]);
}
void inorder(int node)
{
    if (node == -1)
        return;
    inorder(l[node]);
    cout << (char)(node + 'A');
    inorder(r[node]);
}

void postorder(int node)
{
    if (node == -1)
        return;
    postorder(l[node]);
    postorder(r[node]);
    cout << (char)(node + 'A');
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char a, b, c;
        cin >> a >> b >> c;
        a -= 'A';
        if (b == '.')
            b = -1;
        else
            b -= 'A';
        if (c == '.')
            c = -1;
        else
            c -= 'A';
        l[a] = b;
        r[a] = c;
    }
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
}
