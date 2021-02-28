#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<long long> pref(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> pref[i];
		pref[i] += pref[i - 1];
	}	
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		cout << pref[b] - pref[a - 1] << '\n';
	}
	return 0;
}