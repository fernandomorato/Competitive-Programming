#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for (int& x : v)
		scanf("%d", &x);
	long long ans = 0;
	map<int, int> f;
	for (int i = 0; i < n; i++) {
		v[i] -= (i + 1);
		ans += f[v[i]];
		f[v[i]]++;
	}
	printf("%lld\n", ans);
}

int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		solve();
	}
	return 0; 
}