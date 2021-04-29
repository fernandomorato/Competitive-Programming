#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int nComp;

ll sz[MAXN];

bool vis[MAXN];

vector<int> adj[MAXN];

bool isLucky(int n) {
	while (n) {
		int digit = n % 10;
		if (digit != 4 && digit != 7)
			return false;
		n /= 10;
	}
	return true;
}

void dfs(int cur, int par = -1) {
	sz[nComp]++;
	vis[cur] = true;
	for (int viz : adj[cur]) {
		if (viz == par) 
			continue;
		dfs(viz, cur);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		if (!isLucky(w)) {
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			nComp++;
			dfs(i);
		}
	}
	ll ans = 1ll * n * (n - 1) * (n - 2);
	ll sum = accumulate(sz + 1, sz + nComp + 1, 0ll);
	for (int i = 1; i <= nComp; i++) {
		ans -= sz[i] * (sz[i] - 1) * (sz[i] - 2);
		ans -= sz[i] * (sz[i] - 1) * (sum - sz[i]) * 2;
	}
	cout << ans << '\n';
	return 0; 
}