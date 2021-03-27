#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

int n, cs, cf;

ll dp[2005][2005];

ll solve(int i, int k) {
	if (k < 0) return 0ll;
	if (i > n) return k == 1; 
	if (dp[i][k] != -1) return dp[i][k];
	ll& ans = dp[i][k];
	ans = 0;
	if (i == cs || i == cf) {
		ll op1 = solve(i + 1, k);
		ll op2 = solve(i + 1, k + 1);
		return ans = (op1 + op2) % MOD;
	}
	if (i < cs) {
		ll op1 = (1ll * (k - 1) * solve(i + 1, k - 1)) % MOD;
		ll op2 = (1ll * (k + 1) * solve(i + 1, k + 1)) % MOD;
		return ans = (op1 + op2) % MOD;
	}
	if (i < cf) {
		ll op1 = (1ll * (k - 1) * solve(i + 1, k - 1)) % MOD;
		ll op2 = (1ll * k * solve(i + 1, k + 1)) % MOD;
		return ans = (op1 + op2) % MOD;
	}
	ll op1 = (1ll * (k - 1) * solve(i + 1, k - 1)) % MOD;
	ll op2 = (1ll * (k - 1) * solve(i + 1, k + 1)) % MOD;
	return ans = (op1 + op2) % MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> cs >> cf;
	if (cs > cf) swap(cs, cf);
	memset(dp, -1, sizeof dp);
	cout << solve(1, 0) << '\n';
	return 0; 
}