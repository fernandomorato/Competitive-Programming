#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int l = 0, r = 1e6, best1 = 1e6;
	while (l <= r) {
		int mid = (l + r) >> 1;
		int mn = 1e9;
		for (int i = 0, j = 0; i < n; i++) {
			while (j < m && b[j] <= a[i] + 2 * mid) j--;
			int qtd = i + m - j;
			mn = min(mn, qtd);
		}
		if (mn <= mid) {
			best1 = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	l = 0, r = 1e6;
	int best2 = 1e6;
	while (l <= r) {
		int mid = (l + r) >> 1;
		int mn = 1e9;
		for (int i = m - 1, j = n - 1; i >= 0; i--) {
			while (j >= 0 && a[j] >= b[i] - 2 * mid) j--;
			int qtd = j + m - i;
			mn = min(mn, qtd);
		}
		if (mn <= mid) {
			best2 = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << min(best1, best2) << '\n';
	return 0;
}