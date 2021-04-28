#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

int v[MAXN];

struct Node
{

	int value;
	int mn, mx;
	int range;

	Node(int _x = 0): value(_x), mn(_x), mx(_x), range(1) {}

	Node operator +(const Node &o) const {
		Node ans;
		ans.value = value + o.value;
		ans.mn = min(mn, value + o.mn);
		ans.mx = max(mx, value + o.mx);
		ans.range = ans.mx - ans.mn + 1;
		return ans;
	}

};

class SegmentTree
{
	public:
	
		SegmentTree() {}

		void build(int node, int l, int r) {
			if (l > r) return;
			if (l == r) {
				seg[node] = Node(v[l]);
			} else {
				int m = (l + r) / 2;
				build(2 * node, l, m);
				build(2 * node + 1, m + 1, r);
				seg[node] = seg[2 * node] + seg[2 * node + 1];
			}
		}

		void build(int _n) {
			n = _n;
			build(1, 1, n);
		}

		void query(int node, int l, int r, int ql, int qr) {
			if (ql > r || l > qr) {
				return;
			}
			if (ql <= l && r <= qr) {
				return void (seg[0] = seg[0] + seg[node]);
			}
			int m = (l + r) / 2;
			query(2 * node, l, m, ql, qr);
			query(2 * node + 1, m + 1, r, ql, qr);
		}

		Node query(int l, int r) {
			seg[0] = Node();
			query(1, 1, n, l, r);
			return seg[0];
		}

	private:

		int n;
		Node seg[4 * MAXN];
	
};

SegmentTree seg;

void solve() {
	int n, q;
	string s;
	cin >> n >> q >> s;
	for (int i = 1; i <= n; i++) {
		v[i] = s[i - 1] == '-' ? -1 : 1;
	}
	seg.build(n);
	while (q--) {
		int l, r;
		cin >> l >> r;
		Node ans = seg.query(1, l - 1) + seg.query(r + 1, n);
		cout << ans.range << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0; 
}