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
int color[N];
 
bool bfs(int st){
	queue<int> q;
	color[st] = 1;
	q.push(st);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int u : adj[v]){
			if(color[u] == -1){
				color[u] = !color[v];
				q.push(u);
			}else if(color[u] == color[v]) return false;
		}
	}
	return true;
}
 
int main(){
 
	int n, m;
	scanf("%d %d", &n, &m);
	for1(i, n) color[i] = -1;
	int a, b;
	forn(i, m){
		scanf("%d %d", &a, &b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	for1(i, n){
		if(color[i] == -1){
			if(!bfs(i)){
				puts("IMPOSSIBLE");
				return 0;
			}
		}
	}
	forn(i, n){
		if(i) putchar(' ');
		if(!color[i+1]) color[i+1] = 2;
		printf("%d", color[i+1]);
	}
	putchar('\n');
	return 0;
}