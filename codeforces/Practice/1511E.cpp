#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 5;
const long long MOD = 998244353;

long long dp[MAXN], s[MAXN];

long long expo(long long base, long long e) {
	if (!e) return 1;
	long long ans = expo(base, e / 2);
	ans = (ans * ans) % MOD;
	if (e & 1ll) ans = (ans * base) % MOD;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	long long dpSum = 0;
	for (int i = 1; i <= max(n, m); i++) {
		s[i] = ((2 * s[i - 1]) % MOD + ((i - 1) / 2)) % MOD;
		dp[i] = ((dpSum + s[i]) % MOD + (i / 2)) % MOD;
		dpSum = (dpSum + dp[i]) % MOD;
	}
	vector<vector<char>> grid(n, vector<char>(m));
	int cntWhite = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'o')
				cntWhite++;
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		vector<int> compSizes;
		int curSize = 0;
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '*') {
				compSizes.push_back(curSize);
				curSize = 0;
			} else {
				curSize++;
			}
		}
		compSizes.push_back(curSize);
		for (int sz : compSizes) {
			ans = (ans + ((dp[sz] % MOD) * expo(2, cntWhite - sz) % MOD)) % MOD;

		}
	}
	for (int j = 0; j < m; j++) {
		vector<int> compSizes;
		int curSize = 0;
		for (int i = 0; i < n; i++) {
			if (grid[i][j] == '*') {
				compSizes.push_back(curSize);
				curSize = 0;
			} else {
				curSize++;
			}
		}
		compSizes.push_back(curSize);
		for (int sz : compSizes) {
			ans = (ans + ((dp[sz] % MOD) * expo(2, cntWhite - sz)) % MOD) % MOD;
		}
	}
	cout << ans << '\n';
	return 0; 
}