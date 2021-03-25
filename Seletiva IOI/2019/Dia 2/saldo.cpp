#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int subtree[MAXN], pai[MAXN];

vector<pair<int, int>> adj[MAXN];

void dfs(int v, int p = -1) {
	for (auto e : adj[v]) if (e.first != p) {
		pai[e.first] = v;
		dfs(e.first, v);
		subtree[v] += subtree[e.first];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> subtree[i];
		sum += subtree[i];
	}
	vector<pair<int, pair<int, int>>> edges, aux;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
		edges.push_back({c, {a, b}});
	}
	if (sum != 0) {
		cout << -1 << '\n';
		return 0;
	}
	dfs(1);
	for (auto e : edges) {
		int par = e.second.first;
		int child = e.second.second;
		if (pai[par] == child) swap(par, child);
		if (subtree[child] == 0) {
			aux.push_back(e);
		}
	}
	if ((int) aux.size() < k) {
		cout << -1 << '\n';
		return 0;
	}
	sort(aux.begin(), aux.end());
	int ans = 0;
	for (int i = 0; i < k; i++) {
		ans += aux[i].first;
	}
	cout << ans << '\n';
	return 0;
}