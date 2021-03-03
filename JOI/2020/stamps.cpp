#include <bits/stdc++.h>
using namespace std;

const int N = 205;
const long long LINF = 9e18;

int v[N], n, m;
long long t[N], dp[N][N][N][2];

inline long long dist(int a, int b) {
	if (a > b) return m - a + b;
	return b - a;
}

inline void minself(long long &a, long long b) {
	a = min(a, b);
}

inline int ant(int x) {
	return (x + n - 1) % n;
}

inline int nxt(int x) {
	return (x + 1) % n;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
	}
	t[0] = -1;
	n++;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= n; k++) {
				for (int a = 0; a <= 1; a++) {
					dp[i][j][k][a] = LINF;
				}
			}
		}
	}
	
	dp[0][0][0][0] = 0;
	for (int tam = 0; tam < n; tam++) {
		for (int l = 0; l < n; l++) {
			int r = (l + tam) % n;
			for (int k = 0; k <= tam	; k++) {
				if (min(dp[l][r][k][0], dp[l][r][k][1]) == LINF || nxt(r) == l) continue;
				
				long long cost = dp[l][r][k][0] + dist(v[ant(l)], v[l]);
				minself(dp[ant(l)][r][k + (t[ant(l)] >= cost)][0], cost);
				
				cost = dp[l][r][k][0] + dist(v[l], v[nxt(r)]);
				minself(dp[l][nxt(r)][k + (t[nxt(r)] >= cost)][1], cost);
				
				cost = dp[l][r][k][1] + dist(v[r], v[nxt(r)]);
				minself(dp[l][nxt(r)][k + (t[nxt(r)] >= cost)][1], cost);
				
				cost = dp[l][r][k][1] + dist(v[ant(l)], v[r]);
				minself(dp[ant(l)][r][k + (t[ant(l)] >= cost)][0], cost);
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k <= n; k++) {
				if (min(dp[i][j][k][0], dp[i][j][k][1]) < LINF) {
					ans = max(ans, 1ll * k);
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}