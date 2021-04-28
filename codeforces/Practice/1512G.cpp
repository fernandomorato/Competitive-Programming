#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e7 + 5;

int ans[MAXN];
long long d[MAXN];

int main() {
    for (int i = 1; i < MAXN; i++) {
        d[i] = 1;
        ans[i] = -1;
    }
    ans[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            d[j] += i;
        }
        if (d[i] < 1ll * MAXN && ans[d[i]] == -1) {
            ans[d[i]] = i;
        }
    }
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0; 
}