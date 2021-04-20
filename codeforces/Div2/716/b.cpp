#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

void solve() {
	int n, k;
	scanf("%d %d", &n, &k);
	long long ans = 1;
	for (int i = 1; i <= k; i++) {
		ans = (ans * n) % MOD;
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