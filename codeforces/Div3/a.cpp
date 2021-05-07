#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	set<char> st;
	int j = 0;
	bool flag = true;
	for (int i = 0; i < n; i = j) {
		if (st.count(s[i]))
			flag = false;
		st.insert(s[i]);
		while (j < n && s[j] == s[i])
			j++;
	}
	cout << (flag ? "YES\n" : "NO\n");
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0; 
}