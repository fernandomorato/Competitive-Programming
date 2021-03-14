#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

set<int> cant[MAXN], unvisited;

void dfs(int on) {
	vector<int> nxt;
	for (int to : unvisited) {
		if (!cant[on].count(to)) {
			nxt.push_back(to);
		}
	}
	for (int to : nxt) {
		unvisited.erase(to);
	}
	for (int to : nxt) {
		dfs(to);
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		cant[a].insert(b);
		cant[b].insert(a);
	}
	for (int i = 1; i <= n; i++) {
		unvisited.insert(i);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (unvisited.count(i)) {
			unvisited.erase(i);
			dfs(i);
			ans++;
		}
	}
	printf("%d\n", ans - 1);
	return 0; 
}