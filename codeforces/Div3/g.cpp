#include <bits/stdc++.h>

using namespace std;

const long long LINF = 1e16;

int grid[2005][2005];

long long dist[2005][2005][2];

int vx[] = {0, -1, 0, 1};
int vy[] = {-1, 0, 1, 0};

int n, m;

bool valid(int x, int y, int k) {
	return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != -1 && dist[x][y][k] == LINF);
}

void bfs(int x, int y, int k) {
	queue<pair<int, int>> q;
	dist[x][y][k] = 0;
	q.emplace(x, y);
	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (int idx = 0; idx < 4; idx++) {
			int nx = curX + vx[idx];
			int ny = curY + vy[idx];
			if (valid(nx, ny, k)) {
				dist[nx][ny][k] = dist[curX][curY][k] + 1;
				q.emplace(nx, ny);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int w;
	cin >> n >> m >> w;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			dist[i][j][0] = dist[i][j][1] = LINF;
		}
	}
	bfs(0, 0, 0);
	bfs(n - 1, m - 1, 1);
	long long ans = dist[0][0][1];
	if (ans < LINF)
		ans *= w;
	vector<long long> caras1;
	vector<long long> caras2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] > 0) {
				if (dist[i][j][0] < LINF) 
					caras1.push_back(1ll * w * dist[i][j][0] + grid[i][j]);
				if (dist[i][j][1] < LINF)
					caras2.push_back(1ll * w * dist[i][j][1] + grid[i][j]);
			}
		}
	}
	sort(caras1.begin(), caras1.end());
	sort(caras2.begin(), caras2.end());
	long long d = LINF;
	if (!caras1.empty() && !caras2.empty()) {
		d = caras1[0] + caras2[0];
	}
	ans = min(ans, d);
	if (ans >= LINF) ans = -1;
	cout << ans << '\n';
	return 0; 
}