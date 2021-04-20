#include <bits/stdc++.h>

using namespace std;

bool check(int x) {
	for (int i = 2; i <= x; i++) {
		int cnt = 0;
		while (x % i == 0) {
			x /= i;
			cnt++;
		}
		if (cnt & 1) return true;
	}
	return false;
}

void solve() {
	int n;
	scanf("%d", &n);
	bool yes = false;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (check(x)) yes = true;
	}
	puts(yes ? "YES" : "NO");
}

int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		solve();
	}
	return 0; 
}