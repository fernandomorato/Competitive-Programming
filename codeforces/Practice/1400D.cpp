#include <bits/stdc++.h>

using namespace std;

int n;

struct BIT
{
	long long bit[3005];

	void update(int pos, int value) {
		for (int x = pos; x <= n; x += x & -x) {
			bit[x] += 1ll * value;
		}
	}

	long long query() {
		long long ans = 0;
		for (int x = n; x > 0; x -= x & -x) {
			ans += bit[x];
		}
		return ans;
	}

	void clear() {
		for (int i = 0; i <= n; i++) {
			bit[i] = 0;
		}
	}

} bit;

int freq[3005][2];

void rmv(int x, int i) {
	bit.update(x, -freq[x][0] * freq[x][1]);
	freq[x][i]--;
	bit.update(x, freq[x][0] * freq[x][1]);
}

void add(int x, int i) {
	bit.update(x, -freq[x][0] * freq[x][1]);
	freq[x][i]++;
	bit.update(x, freq[x][0] * freq[x][1]);
}

int v[3005];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		add(v[i], 1);
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		rmv(v[i], 1);
		for (int j = i + 1; j < n; j++) {
			rmv(v[j], 1);
			if (v[i] == v[j]) {
				ans += 1ll * bit.query();
			}
			add(v[j], 0);
		}
		for (int j = i + 1; j < n; j++) {
			rmv(v[j], 0);
			add(v[j], 1);
		}
	}
	cout << ans << '\n';
	bit.clear();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0; 
}