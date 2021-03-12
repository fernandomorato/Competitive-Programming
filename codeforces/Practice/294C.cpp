#include "bits/stdc++.h"
using namespace std;

const long long MOD = 1e9 + 7;

long long fat[1005], inv[1005];

long long fexp(long long b, int e) {
	if (!e) return 1;
	auto u = fexp(b, e >> 1);
	u = (u * u) % MOD;
	if (e & 1) u = (u * b) % MOD;
	return u;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> a(m);
	for (int& x : a) scanf("%d", &x);
	sort(a.begin(), a.end());
	fat[0] = inv[0] = 1;
	for (int i = 1; i <= n; i++) {
		fat[i] = (fat[i - 1] * i) % MOD;
	}
	inv[n] = fexp(fat[n], MOD - 2);
	for (int i = n - 1; i >= 1; i--) {
		inv[i] = (inv[i + 1] * (i + 1)) % MOD;
	}
	int last = 0;
	vector<int> v;
	for (int i = 0; i < m; i++) {
		v.push_back(a[i] - last - 1);
		last = a[i];
	}
	v.push_back(n - last);
	int sum = accumulate(v.begin(), v.end(), 0);
	long long ans = fat[sum];
	for (int x : v) {
		ans = (ans * inv[x]) % MOD;
	}
	for (int i = 1; i < (int) v.size() - 1; i++) {
		if (v[i] > 0) ans = (ans * fexp(2, v[i] - 1)) % MOD;
	}
	printf("%lld\n", ans);
	return 0; 
}