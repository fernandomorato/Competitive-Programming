#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e7 + 5;

int p[MAXN];

void sieve() {
	for (int i = 2; i < MAXN; i++) {
		if (p[i])
			continue;
		for (int j = i; j < MAXN; j += i) {
			p[j]++;
		}
	}
}

void solve() {
	int c, d, x;
	scanf("%d %d %d", &c, &d, &x);
	long long ans = 0;
	for (int i = 1; i * i <= x; i++) {
		if (x % i != 0)
			continue;
		int d1 = i;
		int d2 = x / i;
		if ((d1 + d) % c == 0)
			ans += 1 << p[(d1 + d) / c];
		if (d1 != d2 && (d2 + d) % c == 0)
			ans += 1 << p[(d2 + d) / c];
	}
	printf("%lld\n", ans);
}

int main() {
	sieve();
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		solve();
	}
	return 0; 
}