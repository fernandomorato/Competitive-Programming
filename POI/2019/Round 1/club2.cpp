#include <bits/stdc++.h>

using namespace std;

const int LOG = 31;
const int MAXN = 2e6 + 5;

int n, m;

int v[MAXN];
int prefOR[MAXN];
int prefAND[MAXN];

int lastTurnedOn[LOG];
int lastTurnedOff[LOG];
int firstTurnedOn[LOG];
int firstTurnedOff[LOG];

int p2(int x) {
	int ans = 1;
	while (x--) ans *= 2;
	return ans;
}

int main() {
	scanf("%d %d", &n, &m);
	prefAND[0] = p2(n) - 1;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &v[i]);
		prefAND[i] = v[i];
		prefOR[i] = v[i];
		if (i > 1) {
			prefAND[i] &= prefAND[i - 1];
			prefOR[i] |= prefOR[i - 1];
		}
	}
	for (int b = 0; b < n; b++) {
		lastTurnedOn[b] = lastTurnedOff[b] = 0;
		firstTurnedOn[b] = firstTurnedOff[b] = m + 1;
		for (int i = m; i >= 1; i--) {
			if (v[i] & (1 << b)) {
				lastTurnedOn[b] = i;
				break;
			}
		}
		for (int i = m; i >= 1; i--) {
			if (!(v[i] & (1 << b))) {
				lastTurnedOff[b] = i;
				break;
			}
		}
	}
	long long ans = 0;
	int totalOR = prefOR[m];
	int totalAND = prefAND[m];
	for (int l = m; l > 1; l--) {
		int L = 0, R = m + 1;
		for (int b = 0; b < n; b++) {
			if (v[l] & (1 << b)) {
				firstTurnedOn[b] = l;
			}
			if (!(v[l] & (1 << b))) {
				firstTurnedOff[b] = l;
			}
			if ((totalOR & (1 << b)) && !(prefOR[l - 1] & (1 << b))) {
				R = min(R, lastTurnedOn[b]);
			}
			if (!(totalAND & (1 << b)) && (prefAND[l - 1] & (1 << b))) {
				R = min(R, lastTurnedOff[b]);
			}
			if (totalOR & (1 << b)) {
				L = max(L, firstTurnedOn[b]);
			}
			if (!(totalAND & (1 << b))) {
				L = max(L, firstTurnedOff[b]);
			}
		}
		if (R > L) ans += R - L;
	}
	printf("%lld\n", ans);
	return 0;
}