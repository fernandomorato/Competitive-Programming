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
 
vector<int> adj[N], rev[N], dag[N], comp[N], lista;
int idComp[N], in[N], ans[N], cnt, n, m;
bitset<N> vis;
 
inline int neg(int v){
  if(v > m) return v-m;
  return v+m;
}
 
void dfs(int v){
  vis[v] = 1;
  for(int u : adj[v]) if(!vis[u]){
    dfs(u);
  }
  lista.pb(v);
}
 
void dfs2(int v){
  for(int u : rev[v]) if(!idComp[u]){
    idComp[u] = idComp[v];
    dfs2(u);
  }
}
 
int main(){
  fastio;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    char sig1, sig2;
    int a, b;
    cin >> sig1 >> a >> sig2 >> b;
    if(sig1 == '-') a = neg(a);
    if(sig2 == '-') b = neg(b);
    adj[neg(a)].pb(b);
    rev[b].pb(neg(a));
    adj[neg(b)].pb(a);
    rev[a].pb(neg(b));
  }
  for(int i = 1; i <= 2*m; i++){
    if(!vis[i]) dfs(i);
  }
  reverse(all(lista));
  for(int x : lista){
    if(!idComp[x]){
      idComp[x] = ++cnt;
      dfs2(x);
    }
  }
  for(int i = 1; i <= 2*m; i++){
    comp[idComp[i]].pb(i);
  }
  for(int i = 1; i <= 2*m; i++){
    for(int j : adj[i]){
      if(idComp[i] != idComp[j]){
        dag[idComp[i]].pb(idComp[j]);
        in[idComp[j]]++;
      }
    }
  }
  lista.clear();
  for(int i = 1; i <= cnt; i++){
    if(!in[i]){
      lista.pb(i);
    }
  }
  for(int i = 0; i < len(lista); i++){
    int v = lista[i];
    for(int u : dag[v]){
      in[u]--;
      if(!in[u]) lista.pb(u);
    }
  }
  reverse(all(lista));
  for(int x : lista){
    for(int k : comp[x]){
      if(ans[k] == 0){
        ans[k] = 1;
        ans[neg(k)] = -1;
      }
    }
  }
  for(int i = 1; i <= m; i++){
    if(idComp[i] == idComp[neg(i)]){
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }
  for(int i = 1; i <= m; i++){
    if(ans[i] > 0) cout << '+' << ' ';
    else cout << '-' << ' ';
  }
  cout << endl;
  return 0; 
}