#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e18;
const int MAXN = 1e5 + 5;

ll t[MAXN], x[MAXN];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &t[i], &x[i]);
	}
	t[n] = INF;
	bool left = false;
	int ans = 0;
	ll prevPos = 0, target = 0, timeLeft = 0;
	for (int i = 0; i < n; i++) {
		if (timeLeft == 0) {
			target = x[i];
			timeLeft = (x[i] > prevPos ? x[i] - prevPos : prevPos - x[i]);
			left = (x[i] <= prevPos);
		}
		ll curPos = prevPos;
		if (left) {
			curPos = max(target, prevPos - t[i + 1] + t[i]);
			if (curPos <= x[i] && x[i] <= prevPos)
				ans++;
		} else {
			curPos = min(target, prevPos + t[i + 1] - t[i]);
			if (prevPos <= x[i] && x[i] <= curPos)
				ans++;
		}
		swap(prevPos, curPos);
		timeLeft = max(0ll, timeLeft - t[i + 1] + t[i]);
	}
	printf("%d\n", ans);
}

int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		solve();
	}
	return 0; 
}