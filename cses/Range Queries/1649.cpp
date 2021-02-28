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
int v[N], seg[4*N];
 
void build(int node, int l, int r){
	if(l == r){
		seg[node] = v[l];
	}else{
		int m = (l+r)>>1;
		build(2*node, l, m);
		build(2*node+1, m+1, r);
		seg[node] = min(seg[2*node], seg[2*node+1]);
	}
}
 
void updt(int node, int l, int r, int idx, int x){
 
	if(idx > r || idx < l) return;
 
	if(l == r and r == idx){
		seg[node] = x;
		return;
	}
	int m = (l+r)/2;
 
	updt(2*node, l, m, idx, x);
	updt(2*node+1, m+1, r, idx, x);
 
	seg[node] = min(seg[2*node], seg[2*node+1]);
}
 
int query(int node, int l, int r, int ql, int qr){
	if(qr < l or ql > r) return INF;
	if(ql <= l and r <= qr) return seg[node];
	int m = (l+r)>>1;
	return min(query(2*node, l, m, ql, qr), query(2*node+1, m+1, r, ql, qr));
}
 
int main(){
 
	int n, q;
	scanf("%d %d", &n, &q);
	for1(i, n) scanf("%d", &v[i]);
	build(1, 1, n);
	int k, a, b;
	while(q--){
		scanf("%d %d %d", &k, &a, &b);
		if(k == 1){
			updt(1, 1, n, a, b);
		}else{
			printf("%d\n", query(1, 1, n, a, b));
		}
	}
	
	return 0;
}