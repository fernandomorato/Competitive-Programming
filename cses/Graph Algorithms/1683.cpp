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
 
int comp[N], cnt;
vector<int> lista, adj[N], rev[N];
bitset<N> vis;
 
void dfs(int v){
  vis[v] = 1;
  for(int u : adj[v]){
    if(!vis[u]) dfs(u);
  }
  lista.pb(v);
}
 
void dfs2(int v){
  for(int u : rev[v]){
    if(!comp[u]){
      comp[u] = comp[v];
      dfs2(u);
    }
  }
}
 
int main(){
  fastio;
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    rev[b].pb(a);
  }
  for(int i = 1; i <= n; i++){
    if(!vis[i]) dfs(i);
  }
  reverse(all(lista));
  for(int x : lista){
    if(!comp[x]){
      comp[x] = ++cnt;
      dfs2(x);
    }
  }
  cout << cnt << endl;
  for(int i = 1; i <= n; i++){
    cout << comp[i] << ' ';
  }
  cout << endl;
  return 0; 
}