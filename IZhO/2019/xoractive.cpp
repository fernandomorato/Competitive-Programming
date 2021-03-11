#include "interactive.h"
#include "bits/stdc++.h"
using namespace std;

vector<int> guess(int n) {
	map<int, int> pos;
	int x = ask(1);
	pos[x] = 1;
	for (int i = 0; i < 7; i++) {
		vector<int> v;
		for (int j = 2; j <= n; j++) {
			if (j & (1 << i)) {
				v.push_back(j);
			}
		}
		if (v.empty()) continue;
		vector<int> xor1 = get_pairwise_xor(v);
		multiset<int> st;
		for (int k : xor1) {
			if (k == 0) continue;
			st.insert(k);
		}
		v.push_back(1);
		vector<int> xor2 = get_pairwise_xor(v);
		vector<int> tem;
		for (int k : xor2) {
			if (k == 0) continue;
			auto it = st.find(k);
			if (it == st.end()) {
				tem.push_back(x ^ k);
			} else {
				st.erase(it);
			}
		}
		for (int k : tem) {
			pos[k] |= (1 << i);
		}
	}
	vector<int> ans(n);
	for (auto o : pos) {
		ans[o.second - 1] = o.first;
	}
	return ans;
}