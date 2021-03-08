#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

long long price[16][16], value[1 << 16], dp[1 << 16];

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> price[i][j];
		}
	}
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				for (int k = j + 1; k < n; k++) {
					if (i & (1 << k)) {
						value[i] += price[j][k];
					}
				}
			}
		}
	}
	for (int i = 1; i < (1 << n); i++) {
		dp[i] = -INF;
	}
	for (int i = 0; i < (1 << n); i++) {
		// iterates over all submasks of i
		for (int j = i; j > 0; j = (j - 1) & i) {
			dp[i] = max(dp[i], dp[i ^ j] + value[j]);
		}
	}
	cout << dp[(1 << n) - 1] << '\n';
	return 0;
}