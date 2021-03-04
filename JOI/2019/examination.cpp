#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int S = 320;

struct BIT 
{
	int bit[S][N];

	void update(int x, int y) {
		for (int i = x; i > 0; i -= i & -i) {
			for (int j = y; j > 0; j -= j & -j) {
				bit[i][j]++;
			}
		}
	}

	int query(int x, int y) {
		int ret = 0;
		for (int i = x; i < S; i += i & -i) {
			for (int j = y; j < N; j += j & -j) {
				ret += bit[i][j];
			}
		}
		return ret;
	}
} bit;

struct Query
{
	int x, y, z, id;
	Query() {}
	Query(int _x, int _y, int _z, int _id): x(_x), y(_y), z(_z), id(_id) {}
	bool operator<(Query other) {
		return z > other.z;
	}
} q[N];

struct Aluno 
{
	int a, b, soma;
	Aluno() {}
	Aluno(int _a, int _b): a(_a), b(_b), soma(_a + _b) {}
	bool operator<(Aluno other) {
		return soma > other.soma;
	}
} a[N];

vector<pair<int, int>> cmp[2];
vector<Aluno> bloco[S];
int ans[N];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int s, t;
		scanf("%d %d", &s, &t);
		a[i] = Aluno(s, t);
		cmp[0].emplace_back(s, i);
		cmp[1].emplace_back(t, i);
	}
	
	for (int i : {0, 1}) {
		sort(cmp[i].begin(), cmp[i].end());
	}
	
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		auto it = lower_bound(cmp[0].begin(), cmp[0].end(), make_pair(x, -1));
		x = (int) (it - cmp[0].begin()) + 1;
		it = lower_bound(cmp[1].begin(), cmp[1].end(), make_pair(y, -1));
		y = (int) (it - cmp[1].begin()) + 1;
		q[i] = Query(x, y, z, i);
	}
	
	for (int i = 0; i < (int) cmp[0].size(); i++) {
		a[cmp[0][i].second].a = i + 1;
	}
	for (int i = 0; i < (int) cmp[1].size(); i++) {
		a[cmp[1][i].second].b = i + 1;
	}
	
	sort(a, a + n);
	sort(q, q + n);
	int ptr = 0;
	for (int i = 0; i < m; i++) {
		for (; ptr < n && a[ptr].soma >= q[i].z; ptr++) {
			bit.update(a[ptr].a / S, a[ptr].b);
			bloco[a[ptr].a / S].push_back(a[ptr]);
		}

		ans[q[i].id] = bit.query(q[i].x / S + 1, q[i].y);

		for (auto cara : bloco[q[i].x / S]) {
			ans[q[i].id] += (cara.a >= q[i].x && cara.b >= q[i].y);
		}
	}
	for (int i = 0; i < m; i++) {
		printf("%d\n", ans[i]);
	}
}