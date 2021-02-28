#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll sq(ll x){return x*x;}
 
int modpow(int base, int power, int mod){
	if(power == 0) return 1%mod;
	ll ans = modpow(base, power/2, mod);
	ans = (ans*ans)%mod;
	if(power%2 == 1) ans = (ans*base)%mod;
	return ans%mod;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while(n--){
		int a, b, c;
		cin >> a >> b >> c;
		int mod = 1e9+7;
		int aux = modpow(b, c, mod-1)%mod;
		cout << modpow(a, aux, mod)%mod << '\n';
	}
	return 0;
}