#include <bits/stdc++.h>

using namespace std;

const long long LINF = 1e18;

int get(int x) {
	return x < 0 ? 0 : x;
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k = 0;
	vector<int> ovelhas;
	for (int i = 0; i < n; i++) {
		if (s[i] == '*') {
			k++;
			ovelhas.push_back(i);
		}
	}
	if (k == 0) {
		cout << 0 << '\n';
		return;
	}
	vector<int> pos(k);
	pos[k / 2] = ovelhas[k / 2];
	for (int i = k / 2 + 1; i < k; i++) {
		pos[i] = pos[i - 1] + 1;
	}
	for (int j = k / 2 - 1; j >= 0; j--) {
		pos[j] = pos[j + 1] - 1;
	}
	long long ans = 0;
	for (int i = 0; i < k; i++) {
		ans += abs(pos[i] - ovelhas[i]);
	}
	cout << ans << '\n';
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0; 
}