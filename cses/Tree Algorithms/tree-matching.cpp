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
int nivel[N], pai[N];
 
void dfs(int v, int p = -1){
  for(int u : adj[v]) if(u != p){
    nivel[u] = nivel[v] + 1;
    pai[u] = v;
    dfs(u, v);
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
  vector<int> caras(n);
  iota(all(caras), 1);
  sort(all(caras), [&](int a, int b){return nivel[a] > nivel[b];});
  vector<int> foi(n, 0);
  int ans = 0;
  for(int x : caras){
    if(foi[x-1] or !pai[x]) continue;
    if(!foi[pai[x]-1]){
      foi[x-1] = foi[pai[x]-1] = 1;
      ans++;
    }
  }
  cout << ans << '\n';
  return 0; 
}