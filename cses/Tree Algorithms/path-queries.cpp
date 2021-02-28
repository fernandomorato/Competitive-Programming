#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
#define fs first
#define sc second
#define pb push_back
//#define int long long
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
 
namespace seg{
 
  ll *v, seg[4*N];
  int n;
 
  void build(int node = 1, int l = 0, int r = n-1){
    if(l == r) seg[node] = v[l];
    else{
      int m = (l+r)>>1;
      build(2*node, l, m);
      build(2*node+1, m+1, r);
      seg[node] = seg[2*node] + seg[2*node+1];
    }
  }
 
  void build(int _n, ll *_v){
    v = _v;
    n = _n;
    build();
  }
 
  void update(int idx, ll x, int node = 1, int l = 0, int r = n-1){
    if(r < idx or idx < l) return;
    if(l == r and r == idx){
      seg[node] = v[idx] = x;
      return;
    }
    int m = (l+r)>>1;
    update(idx, x, 2*node, l, m);
    update(idx, x, 2*node+1, m+1, r);
    seg[node] = seg[2*node] + seg[2*node+1];
  }
 
  ll query(int ql, int qr, int node = 1, int l = 0, int r = n-1){
    if(l > qr or ql > r) return 0LL;
    if(ql <= l and r <= qr) return seg[node];
    int m = (l+r)>>1;
    return query(ql, qr, 2*node, l, m) + query(ql, qr, 2*node+1, m+1, r);
  }
 
};
 
namespace hld{
 
  vector<int> adj[N];
  int sz[N], pos[N];
  int h[N], pai[N], t;
  ll arr[N], value[N];
 
  void dfs(int v, int p = -1){
    sz[v] = 1;
    for(int& u : adj[v]) if(u != p){
      dfs(u, v);
      sz[v] += sz[u];
      if(sz[u] > sz[adj[v][0]]) swap(u, adj[v][0]);
    }
  }
 
  void build_hld(int v, int p = -1){
    pos[v] = t++;
    arr[pos[v]] = value[v];
    for(int u : adj[v]) if(u != p){
      pai[u] = v;
      h[u] = (adj[v][0] == u ? h[v] : u);
      build_hld(u, v);
    }
  }
 
  void build(){
    t = 0;
    h[0] = 0;
    dfs(0);
    build_hld(0);
    seg::build(t, arr);
  }
 
  void update_node(int v, ll x){
    seg::update(pos[v], x);
  }
 
  ll query_path(int a, int b){
    if(pos[b] > pos[a]) swap(a, b);
    if(h[a] == h[b]) return seg::query(pos[b], pos[a]);
    return seg::query(pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
  }
 
};
 
int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for(int i = 0; i < n; i++){
    cin >> hld::value[i];
  }
  for(int i = 0; i < n-1; i++){
    int a, b;
    cin >> a >> b;
    a--, b--;
    hld::adj[a].pb(b);
    hld::adj[b].pb(a);
  }
  hld::build();
  while(q--){
    int tipo;
    cin >> tipo;
    if(tipo&1){
      int s;
      ll x;
      cin >> s >> x;
      hld::update_node(s-1, x);
    }else{
      int s;
      cin >> s;
      cout << hld::query_path(0, s-1) << '\n';
    }
  }
  return 0; 
}