#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		v[x] = i;
	}	
	int ans = 1;
	for (int i = n - 1; i >= 1; i--) {
		if (v[i] > v[i + 1]) ans++;
	}
	cout << ans << '\n';
	return 0;
}