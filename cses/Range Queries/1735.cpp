#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
//#define int long long
#define endl '\n'
#define fs first
#define sc second
#define pb push_back
#define len(x) ((int)(x).size())     
#define all(x) (x).begin(), (x).end()
#define test int _; cin >> _; while(_--)
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
 
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
 
ll gcd(ll a, ll b){return (b == 0LL ? a : gcd(b, a%b));}
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
ll seg[4*N];
pair<ll, ll> lazy[4*N]; // {add, sett}
ll v[N];
 
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
 
void pushdown(int node, int l, int r){                                 
  ll add = lazy[node].fs;
  ll sett = lazy[node].sc;
  if(add + sett == 0) return;
  lazy[node] = make_pair(0LL, 0LL);
  if(sett){
    seg[node] = (r-l+1)*1LL*sett;
    if(l != r){
      lazy[2*node].fs = lazy[2*node+1].fs = 0LL;
      lazy[2*node].sc = lazy[2*node+1].sc = sett;
    }
  }
  if(add){
    seg[node] += (r-l+1)*1LL*add;
    if(l != r){
      if(lazy[2*node].sc){ //se tem sett, eu adiciono no sett
        lazy[2*node].sc += add;
      }else{
        lazy[2*node].fs += add;
      }
 
      if(lazy[2*node+1].sc){
        lazy[2*node+1].sc += add;
      }else{
        lazy[2*node+1].fs += add;
      }
    }
  }
}
 
void pushup(int node, int l, int r){
  pushdown(node, l, r);
  if(l != r){
    int m = (l+r)>>1;
    pushdown(2*node, l, m);
    pushdown(2*node+1, m+1, r);
  }
  seg[node] = seg[2*node] + seg[2*node+1];
}
 
void update(int node, int l, int r, int ql, int qr, int op, ll x){
  if(r < ql or qr < l) return;
  pushdown(node, l, r);
  if(ql <= l and r <= qr){
    if(op == 1){
      lazy[node] = make_pair(x, 0LL);
    }else{
      lazy[node] = make_pair(0LL, x);
    }
    pushdown(node, l, r);
    return;
  }
  int m = (l+r)>>1;
  update(2*node, l, m, ql, qr, op, x);
  update(2*node+1, m+1, r, ql, qr, op, x);
  pushup(node, l, r);
}
 
ll query(int node, int l, int r, int ql, int qr){
  if(r < ql or qr < l) return 0LL;
  pushdown(node, l, r);
  if(ql <= l and r <= qr) return seg[node];
  int m = (l+r)>>1;
  return query(2*node, l, m, ql, qr) + query(2*node+1, m+1, r, ql, qr);
}
 
int32_t main(){
  fastio;
  int n, q;
  cin >> n >> q;
  for(int i = 1; i <= n; i++){
    cin >> v[i];
  }
  build(1, 1, n);
  while(q--){
    int t, a, b;
    cin >> t >> a >> b;
    if(t == 1){
      ll x;
      cin >> x;
      update(1, 1, n, a, b, 1, x);
    }else if(t == 2){
      ll x;
      cin >> x;
      update(1, 1, n, a, b, 2, x);
    }else{
      cout << query(1, 1, n, a, b) << endl;
    }
  }
  return 0;
}