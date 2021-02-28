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
 
int32_t main(){
  fastio;
  int n;
  cin >> n;
  for(int i = 0; i < n-1; i++){
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
 
  function<pii(int)> bfs = [&](int source){
    vector<int> dist(n+1, 0), vis(n+1, 0);
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    int v = 0;
    while(!q.empty()){
      v = q.front();
      q.pop();
      for(int u : adj[v]){
        if(!vis[u]){
          dist[u] = dist[v]+1;
          q.push(u);
          vis[u] = 1;
        }
      }
    }
    return make_pair(v, dist[v]);
  };
 
  cout << bfs(bfs(1).fs).sc << endl;
  return 0;
}