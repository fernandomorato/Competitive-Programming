#include <bits/stdc++.h>
using namespace std;
 
int n, vis[1 << 17], ant[1 << 17];
vector<int> adj[1 << 17];
 
string toString(int v) {
	string ret = "";
	while (v) {
		ret += (v & 1 ? '1' : '0');
		v >>= 1;
	}
	for (int i = (int) ret.size(); i < n; i++) {
		ret += '0';
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
 
void solve(int v, int cnt = 1) {
	vis[v] = 1;
	for (int u : adj[v]) {
		if (!vis[u]) {
			ant[u] = v;
			solve(u, cnt + 1);
		} else if (vis[u] == 1 && cnt == (1 << n)) {
			int cur = v;
			while (cur != -1) {
				cout << toString(cur) << '\n';
				cur = ant[cur];
			}
			exit(0);
		}
	}
	vis[v] = 2;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if ((i ^ (1 << j)) != i) 
				adj[i].push_back(i ^ (1 << j));
			if ((i & (1 << j)) != i) 
				adj[i].push_back(i & (1 << j));
		}
	}
	ant[0] = -1;
	solve(0);
	return 0;
}