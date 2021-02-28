#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
#define fs first
#define sc second
#define pb push_back
//#define int long long
#define len(x) (int)(x).size()     
#define all(x) (x).begin(), (x).end()
#define test int _; cin >> _; while(_--)
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
 
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
 
inline ll gcd(ll a, ll b){while(b){ a %= b; swap(a, b); } return a; }
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
int ans[N][2];
 
void dfs(int v, int p = -1){
  ans[v][0] = ans[v][1] = 0;
  for(int u : adj[v]) if(u != p){
    dfs(u, v);
    if(ans[u][0] + 1 > ans[v][0]){
      ans[v][1] = ans[v][0];
      ans[v][0] = ans[u][0] + 1;
    }else{
      ans[v][1] = max(ans[v][1], ans[u][0]+1);
    }
  }
}
 
void dfs2(int v, int p = -1){
  for(int u : adj[v]) if(u != p){
    int add = ans[v][0];
    if(ans[u][0] + 1 == add) add = ans[v][1];
    if(add+1 > ans[u][0]){
      ans[u][1] = ans[u][0];
      ans[u][0] = add+1;
    }else ans[u][1] = max(ans[u][1], add+1);
    dfs2(u, v);
  }
}
 
int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 0; i < n-1; i++){
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  dfs(1);
  dfs2(1);
  for(int i = 1; i <= n; i++){
    cout << ans[i][0] << ' ';
  }
  cout << endl;
  return 0; 
}