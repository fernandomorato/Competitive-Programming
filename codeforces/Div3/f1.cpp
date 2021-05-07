#include <bits/stdc++.h>

using namespace std;

int query(int x) {
	cout << "? " << 1 << ' ' << x << endl;
	int ans;
	cin >> ans;
	return ans;
}

void solve() {
	int n, t;
	cin >> n >> t;
	int k; cin >> k;
	int l = 1, r = n, best = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		int valor = query(m);
		if (m - valor >= k) 
			best = m, r = m - 1;
		else
			l = m + 1;
	}
	cout << "! " << best << endl;
}

int main() {
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0; 
}