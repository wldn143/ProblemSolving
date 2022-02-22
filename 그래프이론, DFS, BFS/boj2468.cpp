#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int a[101][101], visited[101][101],x,y,ret;

void dfs(int y, int x,int h) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
		if (a[ny][nx] > h && !visited[ny][nx]) {
			dfs(ny, nx,h);
		}
	}
	return;
}

int main()
{
	int max = 0;
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			a[i][j] = x;
		}
	}

	for (int h = 0; h <= 100; h++) {
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] > h && !visited[i][j]) {
					dfs(i, j, h);
					ret++;
				}
			}
		}
		if (ret > max) {
			max = ret;
		}
		ret = 0;
	}
	cout << max;

}

