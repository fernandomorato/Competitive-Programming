#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
#define fs first
#define sc second
#define pb push_back
#define len(x) ((int)(x).size())
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
 
const ll linf = 1e18;
const int inf = 1e9;
const int mod = 1e9+7;
 
/// command for char arrays with spaces -> scanf(" %[^\n]", text);
 
////////////////////////// Solution starts below. //////////////////////////////
 
const int N = 1e5+5;
vi adj[N];
int color[N], p[N];
int inicio, final;
 
bool dfs(int v){
  color[v] = 1;
  for(int u : adj[v]){
    if(u == p[v]) continue;
    if(color[u] == 1){
      inicio = u;
      final = v;
      return true;
    }else if(color[u] == 0){
      p[u] = v;
      if(dfs(u)) return true;
    }
  }
  color[v] = 2;
  return false;
}
 
int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  int a, b;
  for(int i = 0; i < m; i++){
    scanf("%d %d", &a, &b);
    adj[a].pb(b);
    adj[b].pb(a);
  }
  inicio = -1;
  for(int i = 1; i <= n; i++){
    if(color[i] == 0 and dfs(i)) break;
  }
  if(inicio != -1){
    vector<int> ciclo;
    ciclo.pb(inicio);
    for(int v = final; v != inicio; v = p[v]){
      ciclo.pb(v);
    }
    ciclo.pb(inicio);
    printf("%d\n", (int)ciclo.size());
    for(int x : ciclo){
      printf("%d ", x);
    }
    putchar('\n');
  }else{
    printf("IMPOSSIBLE\n");
  }  
  return 0;
}