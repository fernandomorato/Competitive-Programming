#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
#define fs first
#define sc second
#define pb push_back
#define len(x) ((int)(x).size())
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
 
const ll linf = 1e18;
const int inf = 1e9;
const int mod = 1e9+7;
 
/// command for char arrays with spaces -> scanf(" %[^\n]", text);
 
////////////////////////// Solution starts below. //////////////////////////////
 
const int N = 2e5+5;
ll v[N];
 
struct cell{
	ll pref, suff, total, best;
};
 
cell t[4*N];
 
cell make_cell(ll v){
	cell ans;
	ans.total = v;
	ans.pref = ans.suff = ans.best = max(0LL, v);
	return ans;
}
 
cell combine(cell l, cell r){
	cell ans;
	ans.total = l.total + r.total;
	ans.pref = max(l.pref, l.total + r.pref);
	ans.suff = max(r.suff, r.total + l.suff);
	ans.best = max({l.best, r.best, l.suff + r.pref});
	return ans;
}
 
void build(int node, int l, int r){
	if(l == r){
		t[node] = make_cell(v[l]);
		return;
	}
	int m = (l+r)/2;
	build(2*node, l, m);
	build(2*node+1, m+1, r);
	t[node] = combine(t[2*node], t[2*node+1]);
}
 
void update(int node, int l, int r, int idx, ll v){
	if(idx < l or idx > r) return;
	if(l == r and r == idx) t[node] = make_cell(v);
	else{
		int m = (l+r)/2;
		if(idx <= m) update(2*node, l, m, idx, v);
		else update(2*node+1, m+1, r, idx, v);
		t[node] = combine(t[2*node], t[2*node+1]);	
	}
}
 
cell query(int node, int l, int r, int ql, int qr){
	if(ql > r or qr < l) return make_cell(0LL);
	if(ql <= l and r <= qr) return t[node];
	int m = (l+r)/2;
	return combine(query(2*node, l, m, ql, qr), query(2*node+1, m+1, r, ql, qr));
}
 
int main(){
 
	fastio;
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}
	build(1, 1, n);
	int k;
	ll x;
	while(q--){
		cin >> k >> x;
		update(1, 1, n, k, x);
		cout << query(1, 1, n, 1, n).best << endl;
	} 
	
	return 0;
}