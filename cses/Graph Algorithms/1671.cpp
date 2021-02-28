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
 
const int N = 1e5+5;
vector<pair<int, ll> > adj[N];
ll dist[N];
int n, m;
bitset<N> vis;
 
void dijkstra(int source){
	dist[source] = 0LL;
	set<pair<ll, int> > st;
	st.insert({0LL, source});
	while(!st.empty()){
		int v = st.begin()->sc;
		st.erase(st.begin());
		if(vis[v]) continue;
		vis[v] = 1;
		for(auto e : adj[v]){
			ll w = e.fs;
			int u = e.sc;
			if(dist[u] > dist[v]+w){
				dist[u] = dist[v]+w;
				st.insert({dist[u], u});
			}
		}
	}
}
 
int main(){
 
	scanf("%d %d", &n, &m);
	for1(i, n) dist[i] = LINF;
	int a, b;
	ll c;
	for(int i = 0; i < m; i++){
		scanf("%d %d %lld", &a, &b, &c);
		adj[a].pb({c, b});
	}
	dijkstra(1);
	for1(i, n){
		printf("%lld ", dist[i]);
	}
	putchar('\n');
	return 0;
}