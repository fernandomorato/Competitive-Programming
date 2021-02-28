#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define len(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> pll;
 
template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
template<typename T>
inline T mod(T n, T mod){ T res = n%mod; if(res < 0) res += mod; return res; }
 
/// command for char arrays with spaces -> scanf(" %[^\n]", text);
 
////////////////////////// Solution starts below. //////////////////////////////
 
const int N = 2505;
int n, m;
vi adj[N];
bitset<N> vis;
 
bool dfs(int v, int dest){
  vis[v] = 1;
  for(int u : adj[v]){
    if(u == dest) return true;
    if(vis[u]) continue;
    if(dfs(u, dest)) return true;
  }
  return false;
}
 
int main(){
  fastio;
  cin >> n >> m;
  vector<pair<int, pii> > edges;
  while(m--){
    int a, b;
    ll p;
    cin >> a >> b >> p;
    edges.pb({a, {b, p}});
    adj[a].pb(b);
  } 
  vector<ll> dist(n+1, -INF<ll>);
  dist[1] = 0;
  for(int i = 1; i <= n-1; i++){
    for(auto e : edges){
      dist[e.sc.fs] = max(dist[e.sc.fs], dist[e.fs] + 1LL*e.sc.sc);
    }
  }
  vector<ll> ant = dist;
  for(auto e : edges){
    dist[e.sc.fs] = max(dist[e.sc.fs], dist[e.fs] + 1LL*e.sc.sc);
  }
  int flag = false;
  for(int i = 1; i <= n; i++){
    if(ant[i] < dist[i]){
      bool f1 = dfs(1, i);
      vis.reset();
      if(!f1) continue;
      bool f2 = dfs(i, n);
      if(!f2) continue;
      flag = true;
      break;
    }
    vis.reset();
  }
  if(flag) cout << -1 << endl;
  else cout << dist[n] << endl;
  return 0;
}