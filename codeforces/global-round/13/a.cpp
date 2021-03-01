#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, q; 
	cin >> n >> q;
	int k0 = 0, k1 = 0;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		if (v[i]) k1++;
		else k0++;
	}
	for (int i = 0; i < q; i++) {
		int o, k;
		cin >> o >> k;
		if (o == 1) {
			if (v[k]) {
				v[k] = 0;
				k1--;
				k0++;
			} else {
				v[k] = 1;
				k0--;
				k1++;
			}
		} else {
			if (k <= k1) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	while (tt--) {
		solve();
	}
	return 0;
}