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
vector<pair<int, ll>> adj[N];
vector<int> dag[N];
ll dist[N];
bitset<N> vis;
int n, m, in[N], maior[N], menor[N], quant[N], dist2[N];
 
void dijkstra(int s){
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.push({0, s});
  dist[s] = 0;
  while(!pq.empty()){
    int v = pq.top().sc;
    pq.pop();
    if(vis[v]) continue;
    for(pii e : adj[v]){
      int u = e.fs;
      ll w = e.sc;
      if(dist[u] > dist[v] + w){
        dist[u] = dist[v] + w;
        pq.push({dist[u], u});
      }
    }
  }
}
 
void dfs(int v){
  vis[v] = 1;
  for(pii e : adj[v]){
    int u = e.fs;
    ll w = e.sc;
    if(!vis[u]) dfs(u);
    if(dist[v] + w == dist[u]){
      dag[v].pb(u);
      in[u]++;
    }
  }
}
 
int32_t main(){
  fastio;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].pb({b, 1LL*c});
  }
  for(int i = 1; i <= n; i++) dist[i] = LINF;
  dijkstra(1);
  dfs(1);
  vector<int> lista;
  lista.pb(1);
  quant[1] = 1;
  for(int i = 1; i <= n; i++){
    menor[i] = INF;
    maior[i] = 0;
  }
  menor[1] = maior[1] = 0;
  for(int i = 0; i < len(lista); i++){
    int v = lista[i];
    for(int u : dag[v]){
      quant[u] = mod(quant[u] + quant[v], MOD);
      menor[u] = min(menor[u], menor[v]+1);
      maior[u] = max(maior[u], maior[v]+1);
      in[u]--;
      if(!in[u]) lista.pb(u);
    }
  }
  cout << dist[n] << ' ' << quant[n] << ' ' << menor[n] << ' ' << maior[n] << '\n';
  return 0;
}