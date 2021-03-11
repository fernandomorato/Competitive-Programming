#include <bits/stdc++.h>

constexpr int maxn = 2e5 + 5;

struct Node
{
	int value = 0;
	Node *l, *r;

	Node() {
		value = 0;
		l = r = NULL;
	}

};

Node *seg[maxn];

void build(Node *root, int l, int r) {
	if (l == r) {
		return;
	} else {
		int m = (l + r) >> 1;
		root->l = new Node(), root->r = new Node();
		build(root->l, l, m), build(root->r, m + 1, r);
	}
}

void update(Node *old, Node *root, int l, int r, int x) {
	if (l == r) {
		root->value = 1;
	} else {
		int m = (l + r) >> 1;
		if (x <= m) {
			if (!root->l) root->l = new Node();
			root->r = old->r;
			update(old->l, root->l, l, m, x);
		} else {
			root->l = old->l;
			if (!root->r) root->r = new Node();
			update(old->r, root->r, m + 1, r, x);
		}
		root->value = root->l->value + root->r->value;
	}
}

int query(Node *root, int l, int r, int ql, int qr) {
	if (ql > r || l > qr) return 0;
	if (ql <= l && r <= qr) return root->value;
	int m = (l + r) >> 1;
	return query(root->l, l, m, ql, qr) + query(root->r, m + 1, r, ql, qr);
}

long long c2(int a) {
	return 1ll * a * (a - 1) / 2;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n, q;
	std::cin >> n >> q;
	std::vector<std::pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int y;
		std::cin >> y;
		v.push_back({y, i + 1});
	}
	std::sort(v.begin(), v.end());
	seg[0] = new Node();
	build(seg[0], 1, n);
	for (int i = 0; i < n; i++) {
		seg[i + 1] = new Node();
		update(seg[i], seg[i + 1], 1, n, v[i].second);
	}
	for (int i = 0; i < q; i++) {
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		int up = query(seg[n], 1, n, 1, n) - query(seg[y2], 1, n, 1, n);
		int left = query(seg[n], 1, n, 1, x1 - 1);
		int right = query(seg[n], 1, n, 1, n) - query(seg[n], 1, n, 1, x2);
		int down = query(seg[y1 - 1], 1, n, 1, n);
		int corner1 = query(seg[y1 - 1], 1, n, 1, x1 - 1);
		int corner2 = down - query(seg[y1 - 1], 1, n, 1, x2);
		int corner3 = left - query(seg[y2], 1, n, 1, x1 - 1);
		int corner4 = right - query(seg[y2], 1, n, 1, n) + query(seg[y2], 1, n, 1, x2);
		long long ans = 0;
		ans += c2(up) + c2(left) + c2(right) + c2(down) - c2(corner1)
		- c2(corner2) - c2(corner3) - c2(corner4);
		std::cout << c2(n) - ans << '\n';
	}
	return 0;
}