#include <bits/stdc++.h>

using namespace std;

// usa Kruskal Reconstruction Tree

const int MAXN = 1e6 + 5;
const int MAXL = 21;

int qtdVertices;
int p[MAXN];
int peso[MAXN];
int valor[MAXN];
int anc[MAXN][MAXL];

vector<int> adj[MAXN];

int find(int v) {
	return p[v] == v ? v : p[v] = find(p[v]);
}

void join(int v, int u, int w) {
	v = find(v);
	u = find(u);
	if (v == u) return;
	int newRoot = ++qtdVertices;
	p[v] = p[u] = newRoot;
	adj[newRoot].push_back(v);
	adj[newRoot].push_back(u);
	anc[v][0] = anc[u][0] = newRoot;
	valor[newRoot] += valor[v] + valor[u];
	peso[newRoot] = w;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> valor[i];
		p[i] = i;
	}
	for (int i = n + 1; i <= n + m; i++) {
		p[i] = i;
	}
	vector<pair<int, pair<int, int>>> edges;
	for (int i = 0; i < m; i++) {
		int v, u, w;
		cin >> v >> u >> w;
		edges.push_back({w, {v, u}});
	}
	sort(edges.begin(), edges.end());
	qtdVertices = n;
	for (auto e : edges) {
		int w = e.first;
		int v = e.second.first;
		int u = e.second.second;
		join(v, u, w);
	}
	for (int l = 1; l < MAXL; l++) {
		for (int v = 1; v <= qtdVertices; v++) {
			anc[v][l] = anc[anc[v][l - 1]][l - 1];
		}
	}
	int q;
	cin >> q;
	int lastAns = 0;
	for (int _ = 0; _ < q; _++) {
		int a, k;
		cin >> a >> k;
		k += lastAns;
		for (int i = MAXL - 1; i >= 0; i--) {
			int b = anc[a][i];
			if (b && peso[b] <= k) {
				a = b;
			}
		}
		lastAns = valor[a];
		cout << lastAns << '\n';
	}
	return 0;
}