#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;	

struct Node
{
	int l, r, len;

	Node(): l(0), r(0), len(0) {}

	Node operator+(Node right) {
		// this -> left
		Node ans;
		ans.len += len + right.len + 2 * min(r, right.l);
		ans.l = l + right.l - min(r, right.l);
		ans.r = r - min(r, right.l) + right.r;
		return ans;
	}
};

struct SegTree
{
	Node seg[4 * MAXN];
	string s;

	void build(int node, int l, int r) {
		if (l == r) {
			if (s[l - 1] == ')') {
				seg[node].l++;
			} else {
				seg[node].r++;
			}
		} else {
			int m = (l + r) >> 1;
			build(2 * node, l, m);
			build(2 * node + 1, m + 1 , r);
			seg[node] = seg[2 * node] + seg[2 * node + 1];
		}
	}

	Node query(int node, int l, int r, int ql, int qr) {
		if (ql > r || l > qr) {
			return Node();
		}
		if (ql <= l && r <= qr) {
			return seg[node];
		}
		int m = (l + r) >> 1;
		return query(2 * node, l, m, ql, qr) + query(2 * node + 1, m + 1, r, ql, qr);
	}

} seg;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int n = (int) s.size();
	seg.s = s;
	seg.build(1, 1, n);
	int q; 
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		cout << seg.query(1, 1, n, l, r).len << '\n';
	}
	return 0; 
}