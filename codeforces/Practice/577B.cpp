#include <bits/stdc++.h>

using namespace std;

const int MAXM = 1e6 + 5;
const int MAXN = 1e3 + 5;

int n, m;
bool dp[MAXN][MAXN][2];
int v[MAXM];

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	if (n > m) {
		printf("YES\n");
		return 0;
	}
	dp[0][0][0] = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i + 1][j][0] |= dp[i][j][0];
			dp[i + 1][j][1] |= dp[i][j][1];
			if (dp[i][j][0] || dp[i][j][1]) {
				dp[i + 1][(j + v[i]) % m][1] = true;
			}
		}
	}
	printf("%s\n", dp[n][0][1] ? "YES" : "NO");
	return 0; 
}