#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; 
	cin >> n;
	vector<pair<int, int>> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	vector<pair<int, int>> p;
	p.push_back(v[1]);
	for (int i = 2; i < n; i++) {
		if (v[i].first > v[i - 1].first && v[i].first > v[i + 1].first)
			p.emplace_back(1, v[i].second);
		else if (v[i].first < v[i - 1].first && v[i].first < v[i + 1].first)
			p.emplace_back(0, v[i].second);
	}
	p.push_back(v[n]);
	int k = (int) p.size();
	if (n == 2) {
		if (v[1] < v[2]) {
			p[1].first = 1;
		} else {
			p[0].first = 1;
		}
	} else {
		p[0].first = (p[1].first ? 0 : 1);
		p[k - 1].first = (p[k - 2].first ? 0 : 1);
	}
	int mx = 0;
	for (int i = 0; i < k; i++) {
		mx = max(mx, (i == 0 ? 0 : p[i].second - p[i - 1].second - 1));
		mx = max(mx, (i == k - 1 ? 0 : p[i + 1].second - p[i].second - 1));
	}
	set<int> ans;
	bool gg = false;
	for (int i = 0; i < k; i++) if (p[i].first) {
		int l = (i == 0 ? 0 : p[i].second - p[i - 1].second - 1);
		int r = (i == k - 1 ? 0 : p[i + 1].second - p[i].second - 1);
		if (l > r) swap(l, r);
		if (r == mx && r % 2 != 0) {
			ans.insert(i);
			if (l == r) gg = true;
		}
	}
	cout << (gg && (int) ans.size() == 1) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}