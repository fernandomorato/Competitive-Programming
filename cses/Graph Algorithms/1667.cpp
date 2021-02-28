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
vi adj[N];
int ant[N], dist[N];
bitset<N> vis;
 
int bfs(int source, int target){
	queue<int> q;
	dist[source] = 0;
	q.push(source);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		if(v == target) return dist[target];
		if(vis[v]) continue;
		vis[v] = 1;
		for(int u : adj[v]){
			if(!vis[u] and ant[u] == -1){
				ant[u] = v;
				q.push(u);
				dist[u] = dist[v]+1;
			}
		}
	}
	return -1;
}
 
int main(){
 
	int n, m;
	scanf("%d %d", &n, &m);
	for1(i, n) ant[i] = -1;
	int a, b;
	forn(i, m){
		scanf("%d %d", &a, &b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	vector<int> v;
	int ans = bfs(1, n);
	if(ans == -1) puts("IMPOSSIBLE");
	else{
		printf("%d\n", ans+1);
		int vertex = n;
		do{
			v.pb(vertex);
			vertex = ant[vertex];
		}while(vertex != -1);
		reverse(all(v));
		forn(i, len(v)){
			if(i) putchar(' ');
			printf("%d", v[i]);
		}
		putchar('\n');
	}
	return 0;
}