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
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
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
int v[N], t[4*N];
 
void build(int node, int l, int r){
	if(l == r) t[node] = v[l];
	else{
		int m = (l+r)/2;
		build(2*node, l, m);
		build(2*node+1, m+1, r);
		t[node] = max(t[2*node], t[2*node+1]);
	}	
}
 
int get_room(int node, int l, int r, int ql, int qr, int x){
	if(qr < l or ql > r) return -1;
	if(ql <= l and r <= qr){
		if(t[node] < x) return -1;
		while(l != r){
			int m = (l+r)/2;
			if(t[2*node] >= x){
			    node = 2*node;
			    r = m;
			}else if(t[2*node+1] >= x){
				node = 2*node+1;
				l = m+1;
			}else{
				return -1;
			}
		}
		return l;
	}
	int m = (l+r)/2;
	int left = get_room(2*node, l, m, ql, qr, x);
	if(left != -1) return left;
	return get_room(2*node+1, m+1, r, ql, qr, x);
}
 
void update(int node, int l, int r, int idx, int value){
	if(idx > r or idx < l) return;
	if(l == r and r == idx) t[node] -= value;
	else{
		int m = (l+r)/2;
		update(2*node, l, m, idx, value);
		update(2*node+1, m+1, r, idx, value);
		t[node] = max(t[2*node], t[2*node+1]);
	}
}
 
int main(){
 
	fastio;
	int n, m, x;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}
	build(1, 1, n);
 
	for(int i = 0; i < m; i++){
		if(i) putchar(' ');
		cin >> x;
		int h = get_room(1, 1, n, 1, n, x);
		if(h == -1) h = 0;
		printf("%d", h);
		if(h) update(1, 1, n, h, x);
	}
	putchar('\n');
	return 0;
}