#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
//#define int long long
//#define endl '\n'
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
 
vector<pii> adj[505];
int capacity[505][505];
int n, m;
 
int bfs(int s, int t, vector<int>& p){
  fill(all(p), -1);
  p[s] = -2;
  queue<pii> q;
  q.push({s, INF});
  while(!q.empty()){
    int v = q.front().fs;
    int flow = q.front().sc;
    q.pop();
    for(pii e : adj[v]){
      int u = e.fs;
      if(p[u] == -1 and capacity[v][u]){
        p[u] = v;
        int new_flow = min(flow, capacity[v][u]);
        if(u == t) return new_flow;
        q.push({u, new_flow});
      }
    }
  }
  return 0;
}
 
int get_flow(int s, int t){
  vector<int> p(n);
  int flow = 0, add;
  while((add = bfs(s, t, p))){
    int cur = t;
    while(cur != s){
      int ant = p[cur];
      capacity[ant][cur] -= add;
      capacity[cur][ant] += add;
      cur = ant;
    }
    flow += add;
  }
  return flow;
}
 
int32_t main(){
  fastio;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].pb({b, 1});
    adj[b].pb({a, 0});
    capacity[a][b] = 1;
  }
  int ans = get_flow(0, n-1);
  cout << ans << '\n';
  for(int i = 0; i < ans; i++){
    vector<int> path;
    int cur = 0;
    path.pb(cur);
    while(cur != n-1){
      for(pii e : adj[cur]){
        int nxt = e.fs;
        int vai = e.sc;
        if(vai and !capacity[cur][nxt]){
          capacity[cur][nxt] = 1;
          cur = nxt;
          break;
        }
      }
      path.pb(cur);
    }
    cout << len(path) << '\n';
    for(int x : path) cout << x+1 << ' ';
    cout << '\n';
  }
  return 0; 
}