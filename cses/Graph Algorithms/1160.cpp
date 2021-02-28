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
 
int succ[N], in[N], vis[N], ciclo[N], tam[N], nxt[N], ponta[N], dist[N], tamPonta[N];
int n, q, cntCiclos, cntPontas;
 
void dfs(int v){
  vis[v] = 1;
  int u = succ[v];
  if(!vis[u]) dfs(u);
  else if(vis[u] == 1){
    int k = u;
    cntCiclos++;
    do{
      ciclo[k] = cntCiclos;
      tam[cntCiclos]++;
      dist[k] = tam[cntCiclos];
      k = succ[k];
    }while(k != u);
  }
  vis[v] = 2;
}
 
int solve(int a, int b){
  // Caso 1: A esta no mesmo ciclo que B
  if(ciclo[a] == ciclo[b] and ciclo[a] != -1){
    if(dist[b] >= dist[a]) return dist[b]-dist[a];
    return tam[ciclo[a]] - (dist[a] - dist[b]);
  }
  // Caso 2: A nao esta em um ciclo e B esta em um ciclo
  if(ciclo[a] == -1 and ciclo[b] != -1){
    int ans = 0;
    while(ciclo[a] != ciclo[b]){
      if(ciclo[a] != -1) break;
      ans += tamPonta[ponta[a]] - dist[a] + 1;
      a = nxt[ponta[a]];
    }
    if(ciclo[a] != ciclo[b]) return -1;
    if(dist[b] >= dist[a]) ans += dist[b] - dist[a];
    else ans += tam[ciclo[a]] - (dist[a] - dist[b]);
    return ans;
  }
  if(ciclo[a] == -1 and ciclo[b] == -1){
    int ans = 0;
    while(ponta[a] != ponta[b]){
      if(ciclo[a] != -1) return -1;
      ans += tamPonta[ponta[a]] - dist[a] + 1;
      a = nxt[ponta[a]];
    }
    if(dist[b] < dist[a]) return -1;
    return ans + (dist[b] - dist[a]);
  }
  return -1;
}
 
int main(){
  fastio;
  cin >> n >> q;
  for(int i = 1; i <= n; i++){
    cin >> succ[i];
    in[succ[i]]++;
    ponta[i] = ciclo[i] = -1;
  }
  for(int i = 1; i <= n; i++){
    if(!in[i]){
      dfs(i);
    }
  }
  for(int i = 1; i <= n; i++){
    if(!vis[i]) dfs(i);
    if(!in[i]){
      cntPontas++;
      int k = i;
      while(ponta[k] == -1 and ciclo[k] == -1){
        ponta[k] = cntPontas;
        tamPonta[cntPontas]++;
        dist[k] = tamPonta[cntPontas];
        k = succ[k];
      }
      nxt[ponta[i]] = k;
    }
  }
  while(q--){
    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
  }
  return 0; 
}