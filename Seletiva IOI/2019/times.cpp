#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const long long MOD = 1e9 + 7;

bool eh_bipartido;

int cor[MAXN], cnt[3];

vector<int> adj[MAXN];

void dfs(int v) {
	cnt[cor[v]]++;
	for (int u : adj[v]) {
		if (cor[u] > 0 && cor[u] == cor[v]) {
			eh_bipartido = false;
		} else if (cor[u] == 0) {
			cor[u] = (cor[v] == 1 ? 2 : 1);
			dfs(u);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			int x;
			cin >> x;
			adj[i].push_back(x);
		}
	}
	long long ans = 1;
	for (int i = 1; i <= n; i++) {
		if (!cor[i]) {
			eh_bipartido = true;
			cor[i] = 1;
			dfs(i);
			if (cnt[1] == cnt[2] && eh_bipartido) {
				ans = (ans * 2) % MOD;
			} else {
				ans = 0;
			}
			cnt[1] = cnt[2] = 0;
		}
	}
	cout << ans << '\n';
	return 0;
}