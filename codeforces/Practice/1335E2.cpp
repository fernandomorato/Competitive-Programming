#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

int pref[MAXN][205];
vector<int> pos[205];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= 200; i++) {
		pos[i].clear();
	}
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		pos[x].push_back(i);
		for (int j = 1; j <= 200; j++) {
			pref[i][j] = pref[i - 1][j] + (x == j);
		}
	}
	int ans = 0;
	for (int i = 1; i <= 200; i++) {
		ans = max(ans, (int) pos[i].size());
		for (int j = 0; j < (int) pos[i].size() && j < (int) pos[i].size() - j - 1; j++) {
			int l = pos[i][j];
			int r = pos[i][(int) pos[i].size() - j - 1];
			int mx = 0;
			for (int k = 1; k <= 200; k++) {
				mx = max(mx, pref[r - 1][k] - pref[l][k]);
			}
			ans = max(ans, mx + 2 * (j + 1));
		}
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