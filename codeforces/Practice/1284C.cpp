#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 250005;

ll fat[MAXN];

ll f(int n, int k, ll mod) {
	return 1ll * (n - k + 1) * ((fat[n - k + 1] * fat[k]) % mod) % mod;
}

int main() {
	int n;
	ll mod;
	scanf("%d %lld", &n, &mod);
	fat[0] = 1;
	for (int i = 1; i <= n; i++) {
		fat[i] = (fat[i - 1] * i) % mod;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + f(n, i, mod)) % mod;
	}
	printf("%lld\n", ans);
	return 0; 
}