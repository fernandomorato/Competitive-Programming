#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;
	if (a == b) {
		cout << "YES\n";
	} else if (a > b) {
		cout << "NO\n";
	} else {
		bool gg = true;
		while (b && a) {
			int lsb_b = b & -b;
			int lsb_a = a & -a;
			if (lsb_b < lsb_a) {
				gg = false;
				break;
			}
			b -= lsb_b;
			a -= lsb_a;
		}
		if (b && a == 0) {
			gg = false;
		}
		cout << (gg ? "YES\n" : "NO\n");
	}
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