#include <bits/stdc++.h>

using namespace std;

int v[105];
int aux[105];
int leftmost[105];
int path[105][105];

bool askEdge(int a, int b) {
	cout << 1 << ' ' << a << ' ' << b << endl;
	int ans;
	cin >> ans;
	return ans;
}

int askPath(int a, int l, int r) {
	if (l > r) return 0; 
	cout << 2 << ' ' << a << ' ' << r - l + 1 << ' ';
	for (int i = l; i <= r; i++) {
		cout << v[i] << ' ';
	}
	cout << endl;
	int ans;
	cin >> ans;
	return ans;
}

void printAnswer(int n) {
	cout << 3 << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << path[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void solve() {

	memset(v, 0, sizeof v);
	memset(aux, 0, sizeof aux);
	memset(path, 0, sizeof path);
	memset(leftmost, -1, sizeof leftmost);

	int n;
	cin >> n;
	iota(v, v + n, 0);
	stable_sort(v, v + n, askEdge);
	int j = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		j = min(j, i);
		while (askPath(v[i], 0, j - 1)) {
			j--;
		}
		if (j == i) {
			for (int k = j; k < n; k++) {
				if (leftmost[k] != -1) break;
				leftmost[k] = j;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = leftmost[i]; j < n; j++) {
			path[v[i]][v[j]] = 1;
		}
	}
	printAnswer(n);
	int ok;
	cin >> ok;
	if (ok == -1) 
		exit(0);
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0; 
}