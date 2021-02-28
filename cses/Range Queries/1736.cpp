#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
#define fs first
#define sc second
#define pb push_back
#define int long long
#define len(x) (int)(x).size()     
#define all(x) (x).begin(), (x).end()
#define test int _; cin >> _; while(_--)
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
 
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
 
inline ll gcd(ll a, ll b){while(b){ a %= b; swap(a, b); } return a; }
inline ll mod(ll a, ll b){return ((a%b)+b)%b;}
inline ll expo(ll b, ll p, ll m = MOD){
  ll ans = 1; 
  while(p > 0){
    if(p&1LL) ans = mod(ans*b, m); 
    b = mod(b*b, m); 
    p >>= 1LL;
  } 
  return ans;
}
 
////////////////////////// Solution starts below. //////////////////////////////
 
const int N = 2e5+5;
 
ll v[N], seg[4*N], lazy[4*N], lazy_razao[4*N];
 
void build(int node, int l, int r){
  if(l == r){
    seg[node] = v[l];
  }else{
    int m = (l+r)>>1;
    build(2*node, l, m);
    build(2*node+1, m+1, r);
    seg[node] = seg[2*node] + seg[2*node+1];
  }
}
 
void push(int node, int l, int r){
  if(!lazy_razao[node]) return;
  seg[node] += (r-l+1)*lazy[node] + (((r-l+1)*(r-l+2))/2)*lazy_razao[node];
  if(l != r){
    int m = (l+r)>>1;
    lazy_razao[2*node] += lazy_razao[node];
    lazy_razao[2*node+1] += lazy_razao[node];
    lazy[2*node] += lazy[node];
    lazy[2*node+1] += lazy[node] + (m-l+1)*lazy_razao[node];
  }
  lazy[node] = lazy_razao[node] = 0;
}
 
void update(int node, int l, int r, int ql, int qr){
  push(node, l, r);
  if(l > qr or ql > r) return;
  if(ql <= l and r <= qr){
    lazy[node] += (l-ql);
    lazy_razao[node]++;
    push(node, l, r);
    return;
  }
  int m = (l+r)>>1;
  update(2*node, l, m, ql, qr);
  update(2*node+1, m+1, r, ql, qr);
  seg[node] = seg[2*node] + seg[2*node+1];
}
 
ll query(int node, int l, int r, int ql, int qr){
  push(node, l, r);
  if(l > qr or ql > r) return 0LL;
  if(ql <= l and r <= qr) return seg[node];
  int m = (l+r)>>1;
  return query(2*node, l, m, ql, qr) + query(2*node+1, m+1, r, ql, qr);
}
 
int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for(int i = 1; i <= n; i++){
    cin >> v[i];
  }
  build(1, 1, n);
  while(q--){
    int op, l, r;
    cin >> op >> l >> r;
    if(op&1){
      update(1, 1, n, l, r);
    }else{
      cout << query(1, 1, n, l, r) << '\n';
    }
  }
  return 0; 
}