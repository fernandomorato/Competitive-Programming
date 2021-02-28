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
 
const int N = 1010;
vector<int> adj[N];
int capacity[N][N];
int n, m, k;
 
int bfs(int s, int t, vector<int>& p){
  fill(all(p), -1);
  p[s] = -2;
  queue<pii> q;
  q.push({s, INF});
  while(!q.empty()){
    int v = q.front().fs;
    int flow = q.front().sc; 
    q.pop();
    for(int u : adj[v]){
      if(p[u] == -1 and capacity[v][u]){
        p[u] = v;
        int new_flow = min(flow, capacity[v][u]);
        if(u == t){
          return new_flow;
        }
        q.push({u, new_flow});
      }
    }
  }
  return 0;
}
 
int get_flow(int s, int t){
  vector<int> p(n+m+5, -1);
  int flow = 0, new_flow = 0;
  while((new_flow = bfs(s, t, p))){
    int cur = t;
    while(cur != s){
      int ant = p[cur];
      capacity[ant][cur] -= new_flow;
      capacity[cur][ant] += new_flow;
      cur = ant;
    }
    flow += new_flow;
  }
  return flow;
}
 
int32_t main(){
  fastio;
  cin >> n >> m >> k;
  int s = 0, t = n+m+1;
  for(int i = 1; i <= n; i++){
    adj[s].pb(i);
    adj[i].pb(s);
    capacity[s][i] = 1;
  }
  for(int i = 1; i <= m; i++){
    adj[i+n].pb(t);
    adj[t].pb(i+n);
    capacity[i+n][t] = 1;
  }
  for(int i = 0; i < k; i++){
    int a, b;
    cin >> a >> b;
    b += n;
    adj[a].pb(b);
    adj[b].pb(a);
    capacity[a][b] = 1;
  }
  vector<int> vis(t+1, 0);
  int resp = get_flow(s, t);
  cout << resp << endl;
  for(int v = 1; v <= n; v++){
    for(int u : adj[v]){
      if(vis[u] or u <= n or u == t) continue;
      if(!capacity[v][u]){
        cout << v << ' ' << u-n << endl;
        vis[u] = 1;
        break;
      }
    }
  }
  return 0; 
}