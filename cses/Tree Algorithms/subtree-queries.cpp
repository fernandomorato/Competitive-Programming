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
 
vector<int> adj[N];
int sz[N], pos[N], val[N];
ll arr[N], seg[4*N];
int t;
 
void build(int node, int l, int r){
  if(l == r){
    seg[node] = arr[l];
  }else{
    int m = (l+r)>>1;
    build(2*node, l, m);
    build(2*node+1, m+1, r);
    seg[node] = seg[2*node] + seg[2*node+1];
  }
}
 
void update(int node, int l, int r, int p, ll x){
  if(p < l or r < p) return;
  if(l == r and r == p){
    seg[node] = x;
    return;
  }
  int m = (l+r)>>1;
  update(2*node, l, m, p, x);
  update(2*node+1, m+1, r, p, x);
  seg[node] = seg[2*node] + seg[2*node+1];
}
 
ll query(int node, int l, int r, int ql, int qr){
  if(l > qr or ql > r) return 0LL;
  if(ql <= l and r <= qr) return seg[node];
  int m = (l+r)>>1;
  return query(2*node, l, m, ql, qr) + query(2*node+1, m+1, r, ql, qr);
}
 
void dfs(int v, int p = -1){
  sz[v] = 1;
  pos[v] = t++;
  arr[pos[v]] = val[v];
  for(int u : adj[v]) if(u != p){
    dfs(u, v);
    sz[v] += sz[u];
  }
}
 
int32_t main(){
  fastio;
  int n, q;
  cin >> n >> q;
  for(int i = 0; i < n; i++){
    cin >> val[i];
  }
  for(int i = 0; i < n-1; i++){
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  dfs(0);
  build(1, 0, n-1);
  while(q--){
    int a, b;
    cin >> a >> b;
    b--;
    if(a&1){
      ll s;
      cin >> s;
      update(1, 0, n-1, pos[b], s);
    }else{
      cout << query(1, 0, n-1, pos[b], pos[b]+sz[b]-1) << endl;
    }
  }
  return 0;
}