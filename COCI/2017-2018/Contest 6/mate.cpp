#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int dp[2][2001][26], ans[2001][26][26];

int mod(int a, int b) {
	a %= b;
	if (a < 0) a += b;
	return a;
}

void add_self(int& a, int b) {
	a = mod(a + b, MOD);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str; cin >> str;
	int n = (int) str.size();
	dp[0][0][0] = 1;
	for (int r = 0; r < n; r++) {
		for (int sz = 0; sz <= r; sz++) {
			for (int x = 0; x < 26; x++) {
				add_self(dp[!(r & 1)][sz + 1][str[r] - 'a'], dp[r & 1][sz][x]);
				add_self(dp[!(r & 1)][sz][x], dp[r & 1][sz][x]);
				add_self(ans[sz + 1][x][str[r] - 'a'], dp[r & 1][sz][x]);
				dp[r & 1][sz][x] = 0;
			}
		}
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int l; cin >> l;
		string suffix; cin >> suffix;
		cout << ans[l][suffix[0] - 'a'][suffix[1] - 'a'] << '\n';
	}	
	return 0;
}