#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long dp[3005][3005];

long long mod(long long a, long long b = MOD) {
	a %= b;
	return (a < 0 ? a + b : a);
}

// dp[i][j] = number of ways of having a prefix of size 'i' ending with number 'j'
// Transition:
// 		if sign equals '<' all the numbers k < 'j' don't change because when adding a 'j' to the sequence they don't need to be fixed:
//			dp[i][j] = dp[i - 1][j - 1] + ... + dp[i - 1][1] (prefix sum)
//		if sign equals '>' all the numbers k >= 'j' "turn into" k + 1 because we are adding a 'j' to the sequence so we have to fix a duplicate:
//			dp[i][j] = dp[i - 1][j] + ... + dp[i - 1][i - 1] (suffix sum)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string str;
	cin >> n >> str;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (str[i - 2] == '<') {
				dp[i][j] = mod(dp[i][j] + dp[i - 1][j - 1]);
			} else {
				dp[i][j] = mod(dp[i][j] + dp[i - 1][i - 1] - dp[i - 1][j - 1]);
			}
			// building the prefix sum
			dp[i][j] = mod(dp[i][j] + dp[i][j - 1]);
		}
	}
	cout << dp[n][n] << '\n';
	return 0;
}