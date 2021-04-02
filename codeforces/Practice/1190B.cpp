#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int v[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	map<int, int> freq;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		freq[v[i]]++;
	}
	sort(v, v + n);
	int cnt = 0, bixo = -1;
	bool ff = false;
	for (auto p : freq) {
		if (p.second > 2) {
			ff = true;
			break;
		}
		if (p.second == 2) {
			cnt++;
			bixo = p.first;
		}
	}
	if (cnt >= 2) ff = true;
	else if (cnt == 1) {
		assert(bixo != -1);
		if (bixo == 0 || (bixo > 0 && freq.count(bixo - 1))) ff = true;
	}
	if (ff) {
		cout << "cslnb\n";
		return 0;
	}
	long long nMoves = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			nMoves += v[i];
			v[i] = 0;
		} else if (v[i] - v[i - 1] > 1) {
			nMoves += v[i] - v[i - 1] - 1;
			v[i] = v[i - 1] + 1;
		}
	}
	cout << (nMoves % 2ll == 0 ? "cslnb\n" : "sjfnb\n");
	return 0;
}