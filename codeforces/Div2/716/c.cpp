#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	vector<int> ans(n - 1);
	iota(ans.begin(), ans.end(), 1);
	set<int> caras(ans.begin(), ans.end());
	for (int i = 2; i <= n; i++) {
		if (n % i == 0) {
			for (int j = i; j <= n; j += i) {
				caras.erase(j);
			}
		}
	}
	long long md = 1;
	for (auto x : caras) {
		md = (md * x) % (1ll * n);
	}
	if (md > 1) caras.erase(md);
	printf("%d\n", (int) caras.size());
	for (auto x : caras) {
		printf("%d ", x);
	}
	printf("\n");
}

int main() {
	int tt = 1;
	// scanf("%d", &tt);
	while (tt--) {
		solve();
	}
	return 0; 
}