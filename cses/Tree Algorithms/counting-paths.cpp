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
 
vector<int> adj[N];
 
int sz[N], h[N], pos[N];
int pai[N], ans[N], t;
 
void dfs(int v, int p = -1){
  sz[v] = 1;
  for(int& u : adj[v]) if(u != p){
    dfs(u, v);
    sz[v] += sz[u];
    if(sz[u] > sz[adj[v][0]]) swap(u, adj[v][0]);
  }
}
 
void build(int v, int p = -1){
  pos[v] = t++;
  for(int u : adj[v]) if(u != p){
    pai[u] = v;
    h[u] = (adj[v][0] == u ? h[v] : u);
    build(u, v);
  }
}
 
void update_path(int a, int b){
    if(pos[b] > pos[a]) swap(a, b);
    if(h[a] == h[b]){
      ans[pos[b]]++;
      ans[pos[a]+1]--;
      return;
    }
    ans[pos[h[a]]]++;
    ans[pos[a]+1]--;
    update_path(pai[h[a]], b);
  }
 
int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for(int i = 0; i < n-1; i++){
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  dfs(0);
  build(0);
  while(q--){
    int a, b;
    cin >> a >> b;
    a--, b--;
    update_path(a, b);
  }
  for(int i = 1; i <= n; i++){
    ans[i] += ans[i-1];
  }
  for(int i = 0; i < n; i++){
    cout << ans[pos[i]] << ' ';
  }
  cout << '\n';
  return 0; 
}