#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, a, root;
int map[51][51];
int del[51];
int visited[51];
int visited2[51];
int leaf;
queue<int> q;

void bfs(int x)
{
    q.push(x);
    while (!q.empty())
    {
        int node = q.front();
        int cnt = 0;
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (map[node][i] == 1 && visited[i] == 0)
            {
                cnt++; //자식이 하나라도 잇으면
                visited[node] = 1;
                q.push(i);
                if (node == m || del[node] == -2) //부모의 값이 삭제될 노드이면
                {
                    del[node] = -2;
                    del[i] = -2;
                    map[node][i] = -2; //삭제될 노드의 자식이면 -2로 바꿔줌
                }
                else if (i == m)
                {
                    del[i] = -2;
                    cnt--;
                }
            }
            else if (node == m) //자식 없어도 삭제될 노드면
                del[node] = -2;
        }
        //자식이 없는 leaf노드

        if (cnt == 0 && del[node] != -2 && visited2[node] == 0)
        {
            leaf++;
            visited2[node] = 1;
        }
    }
}
void dfs(int y)
{
    for (int i = 0; i < n; i++)
    {
        if (map[y][i] == 1)
        {
            map[y][i] = -2;
            dfs(i);
        }
    }
    return;
}
int flag = 0;
void tree(int t)
{
    for (int i = 0; i < n; i++)
    {
        if (i == t)
        {
            dfs(t);
            flag = 1;
            break;
        }
    }
    if (flag) //자식이 없는 노드라면
    {
        for (int i = 0; i < n; i++)
        {
            if (map[i][t] == 1)
            {
                map[i][t] = -2;
                break;
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == -1)
            root = i;
        else
        {
            map[a][i] = 1; //부모 자식
        }
    }
    cin >> m; //삭제할 노드

    tree(m);
    bfs(root);

    cout << leaf << "\n";
}
