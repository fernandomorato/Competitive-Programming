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
 
const int N = 4e5+5;
map<int, int> day;
int n, cnt, maxDay;
int ini[N], fim[N];
vector<pair<int, ll>> aux[N];
ll dp[N], p[N];
 
ll solve(int d){
  if(d == 0 or d > maxDay) return 0;
  if(dp[d] != -1) return dp[d];
  if(aux[d].empty()) return dp[d] = solve(d+1);
  ll ans = solve(d+1);
  for(auto p : aux[d]){
    ans = max(ans, solve(p.fs+1)+p.sc);
  }
  return dp[d] = ans;
}
 
int main(){
  fastio;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> ini[i] >> fim[i] >> p[i];
    day[ini[i]];
    day[fim[i]];
  }
  for(auto it = day.begin(); it != day.end(); it++){
    it->sc = ++cnt;
    maxDay = cnt;
  }
  for(int i = 0; i < n; i++){
    ini[i] = day[ini[i]];
    fim[i] = day[fim[i]];
    aux[ini[i]].pb({fim[i], p[i]});
  }
  memset(dp, -1, sizeof dp);
  cout << solve(1) << endl;
  return 0;
}