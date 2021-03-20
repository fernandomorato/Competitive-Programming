#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

struct Segmento
{
	long long sz, mn, mx, idx;

	Segmento(long long a, long long b, int c) {
		mn = a, mx = b; 
		sz = mx - mn + 1;
		idx = c;
	}

	bool operator<(Segmento other) {
		if (mx == other.mx) return mn < other.mn;
		return mx < other.mx;
	}
};

map<long long, vector<int>> mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<Segmento> ss;
	vector<long long> l(n), r(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		if (i > 0) {
			ss.emplace_back(l[i] - r[i - 1], r[i] - l[i - 1], i - 1);
		}
	}
	sort(ss.begin(), ss.end());
	set<long long> st;
	for (int i = 0; i < m; i++) {
		long long x; cin >> x;
		st.insert(x);
		mp[x].push_back(i + 1);
	}
	vector<int> ans(n);
	bool ok = true;
	for (auto s : ss) {
		auto it = st.lower_bound(s.mn);
		if (it == st.end() || *it > s.mx) {
			ok = false;
			break;
		}
		assert(!mp[*it].empty());
		ans[s.idx] = mp[*it].back();
		mp[*it].pop_back();
		if (mp[*it].empty()) st.erase(it);
	}
	for (int i = 0; i < n - 1; i++) {
		if (!ans[i]) ok = false;
	}
	if (ok) {
		cout << "Yes\n";
		for (int i = 0; i < n - 1; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	} else {
		cout << "No\n";
	}
	return 0; 
}