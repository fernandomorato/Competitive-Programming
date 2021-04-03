#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 1e5 + 5;
const int MAXS = 100;
 
vector<int> adj[MAXN];
 
vector<pair<int, int>> caras[MAXN];
 
int dp[MAXN];
 
bool mark[MAXN], blocked[MAXN], valid[MAXN];
 
int solve(int v) {
	if (dp[v] != -1) return dp[v];
	int& ans = dp[v];
	ans = 0;
	valid[v] = !blocked[v];
	for (int u : adj[v]) {
		ans = max(ans, solve(u) + valid[u]);
		valid[v] |= valid[u];
	}
	return ans;
}
 
void merge(int a, int b) {
	vector<pair<int, int>> result;
	int A = (int) caras[a].size();
	int B = (int) caras[b].size();
	result.reserve(A + B + 50);
	int j = 0;
	for (int i = 0; i < A; i++) {
		while (j < B && caras[b][j].first + 1 > caras[a][i].first) {
			if (!mark[caras[b][j].second]) {
				result.push_back({caras[b][j].first + 1, caras[b][j].second});
				mark[caras[b][j].second] = 1;
			}
			j++;
		}
		if (!mark[caras[a][i].second]) {
			result.push_back(caras[a][i]);
			mark[caras[a][i].second] = 1;
		}
	}
	for (; j < B; j++) {
		if (!mark[caras[b][j].second]) {
			result.push_back({caras[b][j].first + 1, caras[b][j].second});
			mark[caras[b][j].second] = 1;
		}
	}
	caras[a].clear();
	int n = (int) result.size();
	for (int i = 0; i < n; i++) {
		mark[result[i].second] = 0;
		if ((int) caras[a].size() < MAXS + 1) caras[a].push_back(result[i]);
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		caras[i].push_back({0, i});
		for (int u : adj[i]) {
			merge(i, u);
		}
	}
	for (int i = 0; i < q; i++) {
		int t, y;
		cin >> t >> y;
		vector<int> bosta;
		for (int j = 0; j < y; j++) {
			int x;
			cin >> x;
			blocked[x] = true;
			bosta.push_back(x);
		}
		if (y > MAXS) {
			for (int j = 1; j <= n; j++) {
				dp[j] = -1;
			}
			int ans = solve(t);
			if (ans == 0 && blocked[t]) ans = -1;
			cout << ans << '\n';
		} else {
			int ans = -1;
			for (auto x : caras[t]) {
				if (!blocked[x.second]) {
					ans = x.first;
					break;
				}
			}
			cout << ans << '\n';
		}
		for (int j : bosta) {
			blocked[j] = false;
		}
	}
	return 0; 
}