#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

pair<int, int> points[MAXN];

bool inserted[MAXN];

vector<int> compress;

struct BIT
{
	int bit[MAXN];

	void update(int x) {
		for (; x < MAXN; x += x & -x) {
			bit[x]++;
		}
	}

	int query(int x) {
		int ans = 0;
		for (; x > 0; x -= x & -x) {
			ans += bit[x];
		}
		return ans;
	}
} bit;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> points[i].first >> points[i].second;
		compress.push_back(points[i].first);
	}	
	sort(compress.begin(), compress.end());
	compress.erase(unique(compress.begin(), compress.end()), compress.end());
	sort(points, points + n, [](pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second > b.second;
	});
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int x = (lower_bound(compress.begin(), compress.end(), points[i].first) - compress.begin()) + 1;
		if (!inserted[x]) {
			bit.update(x);
			inserted[x] = true;
		}
		int left = bit.query(x - 1);
		int mxR = MAXN;
		if (i + 1 < n && points[i + 1].second == points[i].second) {
			mxR = (lower_bound(compress.begin(), compress.end(), points[i + 1].first) - compress.begin()) + 1;
		}
		int right = bit.query(mxR - 1) - bit.query(x);
		ans += 1ll * (left + 1) * (right + 1);
	}
	cout << ans << '\n';
	return 0;
}