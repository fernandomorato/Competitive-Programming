#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

long long ans;
int n, m, tt, cnt_bcc, tam;
int tin[maxn], low[maxn], subtree[2 * maxn];

vector<int> adj[maxn], bcc[2 * maxn];

stack<int> stk;

void dfs(int on, int par = -1) {
	tin[on] = low[on] = ++tt;
	stk.push(on);
	tam++;
	for (int to : adj[on]) if (to != par) {
		if (tin[to]) {
			low[on] = min(low[on], tin[to]);
		} else {
			dfs(to, on);
			low[on] = min(low[on], low[to]);
			if (low[to] >= tin[on]) {
				cnt_bcc++;
				bcc[on].push_back(n + cnt_bcc);
				while (bcc[n + cnt_bcc].empty() || bcc[n + cnt_bcc].back() != to) {
					bcc[n + cnt_bcc].push_back(stk.top());
					stk.pop();
				}
			}
		}
	}
}

void dfs2(int on) {
	subtree[on] = (on <= n);
	for (int to : bcc[on]) {
		dfs2(to);
		subtree[on] += subtree[to];
		if (on > n) {
			ans -= 1ll * ((int) bcc[on].size()) * subtree[to] * (subtree[to] - 1);
		}
	}
	if (on > n) {
		ans -= 1ll * ((int) bcc[on].size()) * (tam - subtree[on]) * (tam - subtree[on] - 1);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
    	int a, b;
    	cin >> a >> b;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
    	if (!tin[i]) {
    		tam = 0;
    		dfs(i);
    		ans += 1ll * tam * (tam - 1) * (tam - 2);
    		dfs2(i);
    	}
    }
    cout << ans << '\n';
    return 0;
}