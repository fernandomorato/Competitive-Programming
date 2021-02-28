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
 
const int N = 2e5+5;
ll v[N], t[4*N];
 
void build(int node, int l, int r){
	if(l == r) t[node] = v[l];
	else{
		int m = (l+r)/2;
		build(2*node, l, m);
		build(2*node+1, m+1, r);
	}
}
 
void update(int node, int l, int r, int ql, int qr, ll x){
	if(qr < l or r < ql) return;
	if(ql <= l and r <= qr){
		t[node] += x;
		return;
	}
	int m = (l+r)/2;
	update(2*node, l, m, ql, qr, x);
	update(2*node+1, m+1, r, ql, qr, x);
}
 
ll query(int node, int l, int r, int p){
	if(l == r) return t[node];
	int m = (l+r)/2;
	if(p <= m){
		return t[node] + query(2*node, l, m, p);
	}else{
		return t[node] + query(2*node+1, m+1, r, p);
	}
}
 
int main(){
 
	int n, q;
	scanf("%d %d", &n, &q);
	for1(i, n){
		scanf("%lld", &v[i]);
	}
	build(1, 1, n);
	int k, a, b;
	ll u;
	while(q--){
		scanf("%d", &k);
		if(k == 1){
			scanf("%d %d %lld", &a, &b, &u);
			update(1, 1, n, a, b, u);
		}else{
			scanf("%d", &a);
			printf("%lld\n", query(1, 1, n, a));
		}
	}
	return 0;
}