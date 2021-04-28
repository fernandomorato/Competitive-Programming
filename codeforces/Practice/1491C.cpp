#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 5e3 + 5;

int s[MAXN];
ll c[MAXN], aux[MAXN];

void solve() {
	int n;
	scanf("%d", &n);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
		c[i] = aux[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		if (i > 0) aux[i] += aux[i - 1];
		c[i] += aux[i];
		if (s[i] > c[i] + 1) {
			ll value = s[i] - c[i] - 1;
			ans += value;
			c[i] += value;
		}
		c[i + 1] += c[i] - s[i] + 1;
		int l = i + 2, r = min(n, i + s[i] + 1);
		aux[l]++, aux[r]--;
	}
	printf("%lld\n", ans);
}

int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		solve();
	}
	return 0; 
}