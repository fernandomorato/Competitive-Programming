#include <bits/stdc++.h>
using namespace std;

bool check(string a, string b) {
	assert((int) a.size() == (int) b.size());
	reverse(b.begin(), b.end());
	for (int i = 0; i < (int) a.size(); i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	 if (k == 0) {
	 	cout << "YES\n";
	 	return;
	 }
	 bool ok = false;
	 int l = 0, r = n - 1;
	 while (l + 1 < r) {
	 	if (l + 1 >= k && check(s.substr(0, l + 1), s.substr(r, n - r))) ok = true;
	 	l++, r--;
	 }
	 cout << (ok ? "YES\n" : "NO\n");
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