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
 
int succ[N], tam[N], ans[N], vis[N], ciclo[N];
int n, cntCiclos;
 
void dfs(int v){
  vis[v] = 1;
  int u = succ[v];
  if(!vis[u]) dfs(u);
  else if(vis[u] == 1){
    cntCiclos++;
    int k = u;
    do{
      ciclo[k] = cntCiclos;
      tam[cntCiclos]++;
      k = succ[k];
    }while(k != u);
  }
  vis[v] = 2;
}
 
int solve(int v){
  if(ans[v] != -1) return ans[v];
  return ans[v] = solve(succ[v]) + 1;
}
 
int main(){
  fastio;
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> succ[i];
    ans[i] = ciclo[i] = -1;
  }
  for(int i = 1; i <= n; i++){
    if(!vis[i]){
      dfs(i);
    }
  }
  for(int i = 1; i <= n; i++){
    if(ciclo[i] != -1){
      ans[i] = tam[ciclo[i]];
    }
  }
  for(int i = 1; i <= n; i++){
    if(ans[i] == -1) ans[i] = solve(i);
    cout << ans[i] << ' ';
  }
  cout << endl;
  return 0; 
}