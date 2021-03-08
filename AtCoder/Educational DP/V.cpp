#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

vector<int> adj[maxn];

long long dp[maxn], n, m;

void dfs(int v, int par = -1) {
	dp[v] = 1;
	for (int u : adj[v]) if (u != par) {
		dfs(u, v);
		dp[v] = (1ll * dp[v] * (dp[u] + 1)) % m;
	}
}

void dfs2(int v, int par = -1, long long from_par = 1) {
	dp[v] = (dp[v] * from_par) % m;
	int k = (int) adj[v].size();
	vector<long long> pref(k + 5);
	pref[0] = 1;
	for (int i = 0; i < k; i++) {
		if (adj[v][i] != par) {
			pref[i + 1] = (pref[i] * (dp[adj[v][i]] + 1)) % m;
		} else {
			pref[i + 1] = (pref[i] * from_par) % m;
		}
	}
	vector<long long> suff(k + 5);
	suff[k] = 1;
	for (int i = k - 1; i >= 0; i--) {
		if (adj[v][i] != par) {
			suff[i] = (suff[i + 1] * (dp[adj[v][i]] + 1)) % m;
		} else {
			suff[i] = (suff[i + 1] * from_par) % m;
		}
	}
	for (int i = 0; i < k; i++) {
		if (adj[v][i] != par) {
			dfs2(adj[v][i], v, (pref[i] * suff[i + 1] + 1) % m);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	dfs2(1);
	for (int i = 1; i <= n; i++) {
		cout << dp[i] << '\n';
	}
	return 0;
}