#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 5;
const long long LINF = 1e18;

int n;

vector<int> adj[MAXN];

long long ans, tot;

long long apples[MAXN], sumSubtree[MAXN], mn[MAXN];

long long gcd(long long a, long long b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

void dfs(int on, int par = -1) {
	sumSubtree[on] = apples[on];
	int nChildren = 0;
	long long lcmChildren = 1;
	for (int to : adj[on]) if (to != par) {
		dfs(to, on);
		nChildren++;
		lcmChildren = lcm(lcmChildren, mn[to]);
		sumSubtree[on] += sumSubtree[to];
	}
	if (lcmChildren > LINF) {
		cout << tot << '\n';
		exit(0);
	}
	mn[on] = (nChildren ? 1ll * nChildren * lcmChildren : 1ll);
}

void dfs2(int on, int par = -1) {
	long long mnChildren = LINF;
	int nChildren = 0;
	for (int to : adj[on]) if (to != par) {
		nChildren++;
		dfs2(to, on);
		mnChildren = min(mnChildren, sumSubtree[to]);
	}
	if (!nChildren) return;
	long long aux = mn[on] / nChildren;
	long long number = mnChildren / aux * aux;
	for (int to : adj[on]) if (to != par) {
		ans += sumSubtree[to] - number;
	}
	sumSubtree[on] = 1ll * nChildren * number;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> apples[i];
		tot += apples[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	dfs2(1);
	cout << ans << '\n';
	return 0; 
}