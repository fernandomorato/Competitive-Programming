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
 
const ll LINF = 1e18;
const int INF = 1e9;
const ll mod = 1e9+7;
 
/// command for char arrays with spaces -> scanf(" %[^\n]", text);
 
////////////////////////// Solution starts below. //////////////////////////////
 
const int N = 1e6+5;
ll dp[N];
 
ll modpow(int x, int p){
	if(p == 0) return 1;
	ll ans = modpow(x, p/2);
	ans = (ans*ans)%mod;
	if(p&1) return (ans*x%mod)%mod;
	return ans;
}
 
ll fat(int n){
	if(n <= 1) return 1%mod;
	if(dp[n] != -1) return dp[n]%mod;
	return dp[n] = (n*fat(n-1))%mod;
}
 
int main(){
	fastio;
	ll n;
	cin >> n;
	memset(dp, -1, sizeof dp);
	while(n--){
		ll a, b;
		cin >> a >> b;
		cout << (((fat(a)*modpow(fat(b), mod-2))%mod)*modpow(fat(a-b), mod-2))%mod << '\n';
	}	
	return 0;
}