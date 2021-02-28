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
 
vector<int> adj[505];
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
    for(int u : adj[v]){
      if(p[u] == -1 and capacity[v][u]){
        p[u] = v;
        int new_flow = min(capacity[v][u], flow);
        if(u == t) return new_flow;
        q.push({u, new_flow});
      }
    }
  }
  return 0;
}
 
int min_cut(int s, int t){
  int flow = 0;
  vector<int> p(n+1);
  int new_flow;
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
 
int main(){
  fastio;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
    capacity[a][b]++;
    capacity[b][a]++;
  }
  int ans = min_cut(1, n);
  if(!ans){
    cout << 0 << '\n';
    return 0;
  }
  vector<int> vis(n+1), aux;
  queue<int> q;
  q.push(1);
  vis[1] = 1;
  while(!q.empty()){
    int v = q.front();
    q.pop();
    aux.pb(v);
    for(int u : adj[v]){
      if(!vis[u] and capacity[v][u]){
        vis[u] = 1;
        q.push(u);
      }
    }
  }
  vector<pii> resp;
  for(int v : aux){
    for(int u : adj[v]){
      if(!vis[u] and !capacity[v][u]){
        resp.pb({v, u});
        ans--;
        if(!ans){
          cout << len(resp) << '\n';
          for(pii e : resp){
            cout << e.fs << ' ' << e.sc << '\n';
          }
          return 0;
        }
      }
    }
  }
  return 0; 
}