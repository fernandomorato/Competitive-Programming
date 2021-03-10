#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; 
	cin >> n;
	vector<long long> vx, vy;
	for (int i = 0; i < n + n; i++) {
		int x, y; 
		cin >> x >> y;
		if (!x) vy.push_back(y);
		else vx.push_back(x);
	}
	sort(vx.begin(), vx.end(), [&](auto a, auto b) { return a * a > b * b; });
	sort(vy.begin(), vy.end(), [&](auto a, auto b) { return a * a > b * b; });
	double ans = 0;
	for (int i = 0; i < n; i++) {
		ans += sqrt(1. * vx[i] * vx[i] + 1. * vy[i] * vy[i]);
	}
	cout << setprecision(10) << fixed << ans << '\n';
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