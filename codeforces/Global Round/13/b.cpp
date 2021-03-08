#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, u, v;
	cin >> n >> u >> v;
	vector<int> x(n);
	bool gg = false, tem1 = false;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		if (i && abs(x[i] - x[i - 1]) > 1) {
			gg = true;
		} else if (i && abs(x[i] - x[i - 1]) == 1) {
			tem1 = true;
		}
	}
	if (gg) {
		cout << 0 << '\n';
	}else if (tem1) {
		cout << min(u, v) << '\n';
	} else {
		cout << v + min(u, v) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}