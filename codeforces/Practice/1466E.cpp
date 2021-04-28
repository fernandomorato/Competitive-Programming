#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 5e5 + 5;

ll v[MAXN];
ll p[65];
int freq[65];

void solve() {
	int n;
	scanf("%d", &n);
	memset(freq, 0, sizeof freq);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
		for (int j = 0; j < 60; j++) {
			if (v[i] & (1ll << j)) {
				freq[j]++;
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll g = 0; // g(i) = (x_i | x1 + x_i | x2 + ... + x_i | xn)
		ll f = 0; // f(i) = (x_i & x1 + x_i & x2 + ... + x_i & xn)
		for (int j = 0; j < 60; j++) {
			if (v[i] & (1ll << j)) {
				g = (g + (1ll * n * p[j]) % MOD) % MOD;
				f = (f + (1ll * freq[j] * p[j]) % MOD) % MOD;
			} else {
				g = (g + (1ll * freq[j] * p[j]) % MOD) % MOD;
			}
		}
		ans = (ans + (g * f) % MOD) % MOD;
	}
	printf("%lld\n", ans);
}

int main() {
	int tt;
	scanf("%d", &tt);
	p[0] = 1;
	for (int i = 1; i < 60; i++) {
		p[i] = (2 * p[i - 1]) % MOD;
	}
	while (tt--) {
		solve();
	}
	return 0; 
}