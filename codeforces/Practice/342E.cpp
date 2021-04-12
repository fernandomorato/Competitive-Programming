#include <bits/stdc++.h>

using namespace std;

const int MAXL = 22;
const int MAXS = 350;
const int INF = 1e9;
const int MAXN = 1e5 + 5;

int n, m;

int d[MAXN];
int depth[MAXN];
int anc[MAXN][MAXL];

vector<int> buffer;
vector<int> adj[MAXN];


void bfs() {
	queue<int> q;
	vector<int> distBfs(n + 1, INF);
	while (!buffer.empty()) {
		distBfs[buffer.back()] = 0;
		q.push(buffer.back());
		buffer.pop_back();
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int viz : adj[cur]) {
			if (distBfs[viz] > distBfs[cur] + 1) {
				distBfs[viz] = distBfs[cur] + 1;
				q.push(viz);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		d[i] = min(d[i], distBfs[i]);
	}
}

void dfs(int cur, int p = -1) {
	d[cur] = INF;
	for (int viz : adj[cur]) {
		if (viz == p) continue;
		anc[viz][0] = cur;
		depth[viz] = depth[cur] + 1;
		dfs(viz, cur);
	}
}

int lca(int v, int u) {
	if (depth[v] > depth[u]) swap(u, v);
	int qtd = depth[u] - depth[v];
	for (int i = MAXL - 1; i >= 0; i--) {
		if (qtd & (1 << i)) {
			u = anc[u][i];
		}
	}
	if (u == v) return v;
	for (int i = MAXL - 1; i >= 0; i--) {
		if (anc[u][i] != anc[v][i]) {
			v = anc[v][i];
			u = anc[u][i];
		}
	}
	return anc[v][0];
}

int distTree(int a, int b) {
	return depth[a] + depth[b] - 2 * depth[lca(a, b)];
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	depth[1] = 1;
	dfs(1);
	for (int i = 1; i < MAXL; i++) {
		for (int v = 1; v <= n; v++) {
			anc[v][i] = anc[anc[v][i - 1]][i - 1];
		}
	}
	buffer.push_back(1);
	for (int i = 0; i < m; i++) {
		int t, x;
		scanf("%d %d", &t, &x);
		if (t == 1) {
			buffer.push_back(x);
			if ((int) buffer.size() == MAXS) {
				bfs();
			}
		} else {
			int ans = d[x];
			for (int v : buffer) {
				ans = min(ans, distTree(x, v));
			}
			printf("%d\n", ans);
		}
	}
}