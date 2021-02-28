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
 
const int N = 5005;
int v[N], n;
ll dp[N][N];
 
ll solve(int l, int r){
  if(l > r) return 0;
  if(dp[l][r] != -1) return dp[l][r];
  if((n-l-r)%2 == 0){ // cara 2
    return dp[l][r] = min(solve(l, r-1), solve(l+1, r));
  }else{ // cara 1
    return dp[l][r] = max(solve(l, r-1)+v[r], solve(l+1, r)+v[l]);
  }
}
 
int main(){
  fastio;
  memset(dp, -1, sizeof dp);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  cout << solve(0, n-1) << endl;
  return 0;
}