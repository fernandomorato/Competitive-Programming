#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 5;

int v[MAXN];

vector<int> indices[MAXN];

struct Node {

	pair<int, int> mxNumber;
	vector<int> v;

	Node(int x = 0) {
		mxNumber = pair<int, int>(1, x);
		v.push_back(x);
	}

	Node(pair<int, int> p, vector<int> _v): mxNumber(p), v(_v) {}

	int getMaxNumber() { return mxNumber.second; }

	Node operator +(const Node &r) const {
		vector<int> ans;
		int j = 0;
		for (int i = 0; i < (int) r.v.size(); i++) {
			while (j < (int) v.size() && v[j] <= r.v[i]) {
				ans.push_back(v[j]);
				j++;
			}
			ans.push_back(r.v[i]);
		}
		while (j < (int) v.size()) {
			ans.push_back(v[j]);
			j++;
		}
		pair<int, int> mx(0, 0);
		pair<int, int> cur(0, 0);
		for (int i = 0; i < (int) ans.size(); i++) {
			mx = max(mx, cur);
			if (cur.second != ans[i]) {
				cur = {1, ans[i]};
			} else {
				cur.first++;
			}
		}
		mx = max(mx, cur);
		return Node(mx, ans);
	}
};

class SegmentTree {
	public:

		void build(int node, int l, int r) {
			if (l == r) {
				seg[node] = Node(v[l]);
			} else {
				int m = (l + r) >> 1;
				build(2 * node, l, m);
				build(2 * node + 1, m + 1, r);
				seg[node] = seg[2 * node] + seg[2 * node + 1];
			}
		}

		void query(int node, int l, int r, int ql, int qr) {
			if (ql > r || l > qr) return;
			if (ql <= l && r <= qr) return void( queryAns.push_back(seg[node].mxNumber.second) );
			int m = (l + r) >> 1;
			query(2 * node, l, m, ql, qr);
			query(2 * node + 1, m + 1, r, ql, qr);
		}

		int query(int ql, int qr, int n) {
			queryAns.clear();
			query(1, 1, n, ql, qr);
			int mx = 0;
			for (int cara : queryAns) {
				int freq = upper_bound(indices[cara].begin(), indices[cara].end(), qr)
				 - lower_bound(indices[cara].begin(), indices[cara].end(), ql);
				mx = max(mx, freq);
			}
			return mx;
		}

	private:

		Node seg[4 * MAXN];
		vector<int> queryAns;
};

SegmentTree seg;

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		indices[v[i]].push_back(i);
	}
	seg.build(1, 1, n);
	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		int total = r - l + 1;
		int ans = seg.query(l, r, n);
		if (2 * ans > total) {
			printf("%d\n", 2 * ans - total);
		} else {
			puts("1");
		}
	}
	return 0; 
}