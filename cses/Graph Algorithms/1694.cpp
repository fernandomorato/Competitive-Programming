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
 
const int N = 505;
vector<int> adj[N];
ll capacity[N][N];
int n, m;
 
ll bfs(int s, int t, vector<int>& p){
  fill(all(p), -1);
  p[s] = -2;
  queue<pair<int, ll>> q;
  q.push({s, LINF}); // {node, current flow}
  while(!q.empty()){
    int v = q.front().fs;
    ll flow = q.front().sc;
    q.pop();
    for(int u : adj[v]){
      if(p[u] == -1 and capacity[v][u]){
        p[u] = v;
        ll new_flow = min(flow, capacity[v][u]);
        if(u == t) return new_flow;
        q.push({u, new_flow});
      }
    }
  }
  return 0LL;
}
 
ll get_flow(int s, int t){
  ll flow = 0LL;
  vector<int> p(n+1);
  ll new_flow;
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
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].pb(b);
    adj[b].pb(a);
    capacity[a][b] += c;
  }
  cout << get_flow(1, n) << '\n';
  return 0; 
}