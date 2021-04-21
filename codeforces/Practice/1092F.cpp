#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

const int MAXN = 2e5 + 5;

lli dp[MAXN];
lli sub[MAXN];
lli cost[MAXN];

vector<int> adj[MAXN];

void dfs(int cur, int p = -1) {
	sub[cur] = cost[cur];
	for (int viz : adj[cur]) {
		if (viz == p) {
			continue;
		}
		dfs(viz, cur);
		dp[cur] += dp[viz] + sub[viz];
		sub[cur] += sub[viz];
	}
}

void dfsRerooting(int cur, int p = -1, lli x = dp[1]) {
	dp[cur] = x;
	for (int viz : adj[cur]) {
		if (viz == p) {
			continue;
		}
		dfsRerooting(viz, cur, x - sub[viz] + (sub[1] - sub[viz]));
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &cost[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	dfsRerooting(1);
	lli ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	printf("%lld\n", ans);
	return 0; 
}