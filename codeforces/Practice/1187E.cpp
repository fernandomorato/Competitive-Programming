#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

int sub[MAXN];

long long best;
long long ans[MAXN];

vector<int> adj[MAXN];

void dfs(int cur, int par = -1) {
	sub[cur] = 1;
	for (int viz : adj[cur]) {
		if (viz == par)
			continue;
		dfs(viz, cur);
		sub[cur] += sub[viz];
		ans[cur] += ans[viz];
	}
	ans[cur] += sub[cur];
}

void reroot(int newRoot, int oldRoot) {
	ans[oldRoot] -= (ans[newRoot] + sub[oldRoot]);
	sub[oldRoot] -= sub[newRoot];
	ans[oldRoot] += sub[oldRoot];
	ans[newRoot] -= sub[newRoot];
	sub[newRoot] += sub[oldRoot];
	ans[newRoot] += ans[oldRoot] + sub[newRoot];
}

void dfsRerooting(int cur, int par = -1) {
	best = max(best, ans[cur]);
	for (int viz : adj[cur]) {
		if (viz == par)
			continue;
		reroot(viz, cur);
		dfsRerooting(viz, cur);
		reroot(cur, viz);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	dfsRerooting(1);
	printf("%lld\n", best);
	return 0; 
}