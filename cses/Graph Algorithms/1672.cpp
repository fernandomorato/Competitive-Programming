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
 
const int MAX = 505;
ll dist[MAX][MAX];
 
int main(){
 
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) dist[i][j] = 0;
			else dist[i][j] = LINF;
		}
	}
	int a, b;
	ll c;
	for(int i = 0; i < m; i++){
		scanf("%d %d %lld", &a, &b, &c);
		dist[a][b] = dist[b][a] = min(dist[a][b], c);
	}
 
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	while(q--){
		scanf("%d %d", &a, &b);
		ll ans = (dist[a][b] == LINF) ? -1 : dist[a][b];
		printf("%lld\n", ans);
	}
	return 0;
}