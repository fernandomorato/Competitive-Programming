#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<long long> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	sort(c.begin(), c.end());
	long long sum = 0, mx = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (c[i] > mx + 1) {
			ans = min(ans, mx + 1);
			break;
		}
		mx = max(mx, c[i] + sum);
		sum += c[i];
	}
	if (ans == 0) ans = sum + 1;
	cout << ans << '\n';
	return 0;
}