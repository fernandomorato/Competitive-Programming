#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	bool ok = v[0] == 0;
	int x = (ok ? -1 : 0);
	for (int i = 1; i < n; i++) {
		if (v[i] != v[i - 1] && v[i] != v[i - 1] + 1) {
			x = v[i - 1] + 1;
			ok = false;
		}
	}
	set<int> st;
	for (int i = 0; i < n; i++) 
		st.insert(v[i]);
	if (k == 0) {
		cout << (int) st.size() << '\n';
		return;
	}
	if (ok) {
		cout << k + (int) st.size() << '\n';
	} else {
		assert(x != -1);
		st.insert((v[n - 1] + x + 1) / 2);
		cout << (int) st.size() << '\n';
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