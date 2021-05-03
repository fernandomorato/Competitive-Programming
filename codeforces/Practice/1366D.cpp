#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e7 + 5;

int p[MAXN];

void sieve() {
	p[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		if (p[i]) 
			continue;
		p[i] = i;
		for (int j = i + i; j < MAXN; j += i) {
			if (!p[j]) 
				p[j] = i;
		}
	}
}

void solve() {
	int n;
	scanf("%d", &n);
	vector<int> d1, d2;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		int a = 1;
		int primo = p[x];
		while (x > 1 && x % primo == 0) {
			x /= primo;
			a *= primo;
		}
		if (x == 1 || a == x) {
			a = x = -1;
		}
		d1.push_back(a);
		d2.push_back(x);
	}
	for (auto x : d1) {
		printf("%d ", x);
	}
	puts("");
	for (auto x : d2) {
		printf("%d ", x);
	}
	puts("");
}

int main() {
	sieve();
	int tt = 1;
	// scanf("%d", &tt);
	while (tt--) {
		solve();
	}
	return 0; 
}