#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 1e9 + 7;
const int N = 1e6 + 5;
 
long long mod(long long a, long long b = MOD) {
	a %= b;
	if (a < 0) a += b;
	return a;
}
 
struct matrix {
	long long m[2][2];
	matrix() {}
	matrix(int a, int b, int c, int d) {
		m[0][0] = a, m[0][1] = b;
		m[1][0] = c, m[1][1] = d;
	}
	matrix operator*(matrix b) {
		matrix c = matrix(0, 0, 0, 0);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					c.m[i][j] = mod(c.m[i][j] + mod(m[i][k] * b.m[k][j]));
				}
			}
		}
		return c;
	}
};
 
matrix expo(matrix b, long long e) {
	if (e == 1) {
		return b;
	}
	matrix u = expo(b, e >> 1ll);
	u = u * u;
	if (e & 1ll) u = u * b;
	return u;
}
 
void solve() {
	int n; cin >> n;
	if (n == 1) {
		cout << 2 << '\n';
		return;
	}
	matrix m = matrix(4, 1, 1, 2);
	m = expo(m, n - 1);
	long long ans = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			ans = mod(ans + m.m[i][j]);
		}
	}
	cout << ans << '\n';
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}