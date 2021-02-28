#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define len(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> pll;
 
template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
template<typename T>
inline T mod(T n, T mod){ T res = n%mod; if(res < 0) res += mod; return res; }
 
/// command for char arrays with spaces -> scanf(" %[^\n]", text);
 
////////////////////////// Solution starts below. //////////////////////////////
 
const int md = 1e9+7;
int dp[505][225255];
int n, sum;
 
int expo(int base, int power){
  if(power == 0) return 1;
  int u = expo(base, power/2)%md;
  u = (1LL*u%md*u%md)%md;
  if(power&1) u = (u%md*base%md)%md;
  return u;
}
 
int solve(int i, int s){
  if(i > n and s == 125250) return 1;
  if(i > n) return 0;
  if(dp[i][s] != -1) return dp[i][s];
  return dp[i][s] = (solve(i+1, s+i)%md + solve(i+1, s-i)%md)%md;
}
 
int main(){
  fastio;
  memset(dp, -1, sizeof dp);
  cin >> n;
  ll aux = solve(1, 125250)%md;
  ll ans = (aux%md * expo(2LL, md-2)%md)%md;
  cout << ans << endl;
  return 0;
}