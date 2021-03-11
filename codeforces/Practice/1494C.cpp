#include "bits/stdc++.h"
using namespace std;

int magic(vector<int> a, vector<int> b) {
	int n = (int) a.size(), m = (int) b.size();
	vector<int> suf(n + 5);
	int j = m - 1;
	for (int i = n - 1; i >= 0; i--) {
		suf[i] += suf[i + 1];
		while (j > 0 && b[j] > a[i]) j--;
		if (j > 0 && b[j] == a[i]) suf[i]++;
	}
	int ans = 0, r = 0, boxes = 0;
	for (int l = 0; l < m; l++) {
		while (boxes < n && a[boxes] <= b[l] + boxes) boxes++;
		while (r < m && b[r] < b[l] + boxes) r++;
		ans = max(ans, r - l + suf[boxes]);
	}
	return ans;
}

void solve() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> a(2, vector<int>());
	vector<vector<int>> b(2, vector<int>());
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[x < 0].push_back((x < 0 ? -x : x));
	}
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		b[x < 0].push_back((x < 0 ? -x : x));
	}
	sort(a[1].begin(), a[1].end());
	sort(b[1].begin(), b[1].end());
	printf("%d\n", magic(a[0], b[0]) + magic(a[1], b[1]));
}

int main(){
	int tt = 1;
	scanf("%d", &tt);
	while (tt--) {
		solve();
	}
	return 0; 
}