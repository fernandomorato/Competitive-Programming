#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const ll mod = 1e9+7;
 
ll sq(ll x){return x*x;}
 
ll expo(ll base, ll power){
	if(power == 0) return 1LL;
	ll ans = 1;
	if(power%2) ans *= base%mod;
	ans *= sq(expo(base, power/2))%mod;
	return ans%mod;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while(n--){
		ll a, b;
		cin >> a >> b;
		cout << expo(a, b)%mod << endl;		
	}
	return 0;
} 