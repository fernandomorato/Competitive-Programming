#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	if (n == 2) {
		puts("-1");
		return;
	}
	vector<vector<int>> v(n, vector<int>(n));
	int cnt = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			v[i][j] = ++cnt;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j % 2 == 0 && i + 1 < n) {
				swap(v[i][j], v[i + 1][j]);
			}
			printf("%d ", v[i][j]);
		}	
		puts("");
	}
}

int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		solve();
	}
	return 0; 
}