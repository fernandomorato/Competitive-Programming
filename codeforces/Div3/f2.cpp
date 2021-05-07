#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 50;

int nBlocks;

int blocks[MAXN / 32];

int ask(int l, int r) {
	cout << "? " << l + 1 << ' ' << r + 1 << endl;
	int ans;
	cin >> ans;
	if (ans == -1)
		exit(0);
	return ans;
}

void initBlocks(int n) {
	for (int l = 0; l < n; l += 32) {
		nBlocks++;
		int r = min(n - 1, l + 31);
		blocks[l / 32] = ask(0, r);
	}
}

int findBlock(int k) {
	int l = 0, r = nBlocks - 1;
	while (l < r) {
		int m = l + (r - l) / 2;
		int qtd = 32 * (m + 1) - blocks[m];
		if (qtd >= k)
			r = m;
		else
			l = m + 1;
	}
	return r;
}

void updateBlocks(int b) {
	for (int i = b; i < nBlocks; i++) {
		blocks[i]++;
	}
}

int main() {
	int n, t;
	cin >> n >> t;
	for (int i = 0; i < t; i++) {
		int k; cin >> k;
		if (i == 0)
			initBlocks(n);
		int l = findBlock(k) * 32;
		int r = min(n - 1, l + 31);
		while (l < r) {
			int m = l + (r - l) / 2;
			int value = m + 1 - ask(0, m);
			if (value >= k)
				r = m;
			else 
				l = m + 1;
		}
		cout << "! " << r + 1 << endl;
		updateBlocks(r / 32); // O(T * (N / 32)) ~ 1e7
	}
	return 0; 
}