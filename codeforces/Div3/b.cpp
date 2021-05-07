#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long n;
	scanf("%lld", &n);
	vector<long long> aux;
	aux.push_back(1);
	for (int i = 0; i < 9; i++) {
		aux.push_back(aux.back() * 10 + 1);
	}
	int cnt = 0;
	long long a = n;
	while (a) {
		cnt++;
		a /= 10;
	}
	int cnt2 = 0;
	for (cnt2 = 1; cnt2 <= 9; cnt2++) {
		if (cnt2 * aux[cnt - 1] > n)
			break;
	}
	printf("%d\n", 9 * (cnt - 1) + cnt2 - 1);
}

int main() {
	int tt;
	scanf("%d", &tt);
	while (tt--) {
		solve();
	}
	return 0; 
}