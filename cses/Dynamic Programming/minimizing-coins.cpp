#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
#define fs first
#define sc second
#define pb push_back
#define len(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n); i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpl;
typedef vector<vl> vvl;
 
template<typename T> void maxself(T &a, T &b){a = max(a, b);};
template<typename T> void minself(T &a, T &b){a = min(a, b);};
 
const ll LINF = 1e18;
const int INF = 1e9;
const int MOD = 1e9+7;
 
/// command for char arrays with spaces -> scanf(" %[^\n]", text);
 
////////////////////////// Solution starts below. //////////////////////////////
 
const int N = 105;
 
int c[N];
 
int main(){
	
	int n, x;
	scanf("%d %d", &n, &x);
	vector<int> c(n);
	for(int& v : c) scanf("%d", &v);
 
	vector<int> dp(x+1, INF);
	dp[0] = 0;
	for(int i = 1; i <= x; i++){
		for(int j = 0; j < n; j++){
			if(i-c[j] >= 0) dp[i] = min(dp[i], dp[i-c[j]]+1);
		}
	}
	if(dp[x] == INF) puts("-1");
	else printf("%d\n", dp[x]);
	return 0;
}