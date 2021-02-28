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
 
vector<int> adj[21];
int dp[21][1<<21], n, m;
 
int solve(int v, int msk){
  if(v == n-1 and msk == (1<<n)-1) return 1;
  if(v == n-1 or msk == (1<<n)-1) return 0;
  if(dp[v][msk] != -1) return dp[v][msk];
  int ans = 0;
  for(int u : adj[v]){
    if(!(msk&(1<<u))){
      ans = (ans + solve(u, msk|(1<<u)))%MOD;
    }
  }
  return dp[v][msk] = ans;
}
 
int main(){
  fastio;
  memset(dp, -1, sizeof dp);
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].pb(b);
  }
  cout << solve(0, 1)%MOD << '\n';
  return 0; 
}