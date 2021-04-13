#include <bits/stdc++.h>
#include "werewolf.h"
 
using namespace std;
 
const int MAXL = 20;
const int INF = 1e9;
const int MAXN = 4e5 + 5;
 
class FenwickTree
{
	public:
 
		FenwickTree(int _n = MAXN - 1) {
			n = _n;
			for (int i = 0; i <= n; i++) {
				bit[i] = 0;
			}
		}
 
		void update(int x, int val) {
			for (; x <= n; x += x & -x)
				bit[x] += val;
		}
 
		int query(int x) {
			int ans = 0;
			for (; x > 0; x -= x & -x) 
				ans += bit[x];
			return ans;
		}
 
	private:
 
		int n;
 
		int bit[MAXN];
 
} bit;
 
class KRT
{
	public:
 
		KRT(int _n = 0): n(_n) {
			curTimer = 0;
			for (int i = 1; i <= n; i++) {
				p[i] = i;
			}
		}
 
		void init(int _n) {
			n = _n;
			for (int i = 1; i <= n; i++) {
				p[i] = i;
			}
		}
 
		int getTin(int v) { return tin[v]; }
		int getTout(int v) { return tout[v]; }
		int getRoot(int v) { return p[v] == v ? v : p[v] = getRoot(p[v]); }
 
		void addEdge(int v, int u, int w, int flag) {
			v = getRoot(v);
			u = getRoot(u);
			if (u == v) return;
			++n;
			p[n] = p[u] = p[v] = n;
			adj[n].push_back(v);
			adj[n].push_back(u);
			anc[v][0] = anc[u][0] = {n, w};
            anc[n][0] = make_pair(n, (flag ? 0 : INF));
		}
 
		void dfs(int cur) {
			tin[cur] = ++curTimer;
			for (int viz : adj[cur]) {
				dfs(viz);
			}
			tout[cur] = curTimer;
		}
 
		int get(int a, int b, int flag) {
			return flag ? max(a, b) : min(a, b);
		}
 
		void buildKRT(int flag) {
			for (int d = 1; d < MAXL; d++) {
				for (int i = 1; i <= n; i++) {
					auto mid = anc[i][d - 1];
					auto target = anc[mid.first][d - 1];
					anc[i][d] = {target.first, get(mid.second, target.second, flag)};
				}
			}
			dfs(n);
		}
 
		bool compare(int limit, int value, int flag) {
			return flag ? limit >= value : limit <= value;
		}
 
		int goUp(int v, int limit, int flag) {
			for (int j = MAXL - 1; j >= 0; j--) {
				if (compare(limit, anc[v][j].second, flag)) {
					v = anc[v][j].first;
				}
			}
			return v;
		}
 
	private:
 
		int n;
		int curLen;
		int curTimer;
 
		int p[MAXN];
		int tin[MAXN];
		int tout[MAXN];
 
		vector<int> adj[MAXN];
 
		pair<int, int> anc[MAXN][MAXL];
 
} krtMin, krtMax;
 
struct Event
{
	int tipo, idx;
	int x, y;
 
	Event() {}
 
	Event(int _t, int _i, int _x, int _y): tipo(_t), idx(_i), x(_x), y(_y) {}
 
	bool operator <(const Event &e) const {
		if (x == e.x) return tipo < e.tipo;
		return x < e.x;
	}
};
 
vector<int> check_validity(int N, vector<int> X, vector<int> Y, vector<int> S, vector<int> E, vector<int> L, vector<int> R) {
	int n = N;
	krtMin.init(n);
	krtMax.init(n);
	vector<pair<int, pair<int, int>>> edges[2];
	int m = (int) X.size();
	for (int i = 0; i < m; i++) {
		X[i]++, Y[i]++;
		edges[0].push_back(make_pair(min(X[i], Y[i]), make_pair(X[i], Y[i])));
		edges[1].push_back(make_pair(max(X[i], Y[i]), make_pair(X[i], Y[i])));
	}
	for (int i : {0, 1}) {
		sort(edges[i].begin(), edges[i].end());
	}
    reverse(edges[0].begin(), edges[0].end());
	for (int i = 0; i < m; i++) {
		int w = edges[0][i].first;
		int v = edges[0][i].second.first;
		int u = edges[0][i].second.second;
		krtMin.addEdge(v, u, w, 0);
	}
	for (int i = 0; i < m; i++) {
		int w = edges[1][i].first;
		int v = edges[1][i].second.first;
		int u = edges[1][i].second.second;
		krtMax.addEdge(v, u, w, 1);
	}
	krtMin.buildKRT(0);
	krtMax.buildKRT(1);
	int q = (int) S.size();
	vector<Event> sweep;
	for (int i = 1; i <= n; i++) {
		int x = krtMax.getTin(i);
		int y = krtMin.getTin(i);
		sweep.emplace_back(0, -1, x, y);
	}
	vector<int> ans(q);
	for (int i = 0; i < q; i++) {
		S[i]++, E[i]++, L[i]++, R[i]++;
		int maxHuman = krtMin.goUp(S[i], L[i], 0);
		int maxWerewolf = krtMax.goUp(E[i], R[i], 1);
		int y1 = krtMin.getTin(maxHuman);
		int y2 = krtMin.getTout(maxHuman);
		int x1 = krtMax.getTin(maxWerewolf);
		int x2 = krtMax.getTout(maxWerewolf);
		sweep.emplace_back(1, i, x1 - 1, y2);
		sweep.emplace_back(1, i, x2, y1 - 1);
		sweep.emplace_back(2, i, x1 - 1, y1 - 1);
		sweep.emplace_back(2, i, x2, y2);
	}
	sort(sweep.begin(), sweep.end());
	for (auto event : sweep) {
		if (event.tipo == 0) {
			bit.update(event.y, 1);
		} else if (event.tipo == 1) {
			ans[event.idx] -= bit.query(event.y);
		} else {
			ans[event.idx] += bit.query(event.y);
		}
	}
	for (int& x : ans) {
		x = !!x;
	}
	return ans;
}