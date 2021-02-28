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
 
const int N = 1e5+5;
vector<int> adj[N];
int n, m, dist[N], p[N];
bitset<N> vis;
 
void dfs(int v){
  dist[v] = (v == n ? 1 : -INF);
  vis[v] = 1;
  for(int u : adj[v]){
    if(!vis[u]){
      p[u] = v;
      dfs(u);
    }
    if(dist[v] < dist[u]+1){
      p[v] = u;
      dist[v] = dist[u]+1;
    }
  }
}
 
int32_t main(){
  fastio;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
  }
  dfs(1);
  if(dist[1] < 0){
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  int v = 1;
  vector<int> ans;
  while(v^n){
    ans.pb(v);
    v = p[v];
  }
  ans.pb(v);
  cout << len(ans) << '\n';
  for(int x : ans){
    cout << x << ' ';
  }
  return 0;
}