#include <iostream>
#include <algorithm>
using namespace std;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int t, n, m, k, a[51][51], ret, visited[51][51], y, x;

void dfs(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
		if (a[nx][ny] == 1 && !visited[nx][ny]) {
			dfs(nx, ny);
		}
	}
	return;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		fill(&a[0][0], &a[0][0] + 51 * 51, 0);
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		ret = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			a[x][y] = 1;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 1 && !visited[i][j]) {
					ret++; dfs(i, j);
				}
			}
		}
		cout << ret<<"\n";

	}
}
