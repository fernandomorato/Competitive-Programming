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
 
////////////////////////// Solution starts below. //////////////////////////////
 
int main(){
  fastio;
  int a, b;
  cin >> a >> b;
  vvi dp(a+1, vi(b+1, INF<int>));
  for(int i = 1; i <= min(a, b); i++){
    dp[i][i] = 0;
  }
  for(int i = 1; i <= a; i++){
    for(int j = 1; j <= b; j++){
      for(int k = 1; k < i; k++){
        dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j] + 1);
      }
      for(int k = 1; k < j; k++){
        dp[i][j] = min(dp[i][j], dp[i][j-k] + dp[i][k] + 1);
      }
    }
  }
  cout << dp[a][b] << endl;
  return 0;
}