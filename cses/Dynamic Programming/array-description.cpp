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
 
const ll MOD = 1e9+7;
 
int main(){
	fastio;
	int n, m;
	cin >> n >> m;
	vector<ll> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	vector<vector<ll>> dp(n, vector<ll>(m+1, 0));
	if(v[0] == 0) fill(all(dp[0]), 1);
	else dp[0][v[0]] = 1;
	for(int i = 1; i < n; i++){
		if(v[i] == 0LL){
			for(int j = 1; j <= m; j++){
				for(int k = j-1; k <= j+1; k++){
					if(k >= 1 and k <= m){
						(dp[i][j] += dp[i-1][k])%=MOD;
					}
				}
			}
		}else{
		  for(int k = v[i]-1; k <= v[i]+1; k++){
		  	if(k >= 1 and k <= m){
		  		(dp[i][v[i]] += dp[i-1][k]) %= MOD;
		  	}
		  }
		}
	}
	ll ans = 0;
	for(int i = 1; i <= m; i++){
		ans += dp[n-1][i];
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}