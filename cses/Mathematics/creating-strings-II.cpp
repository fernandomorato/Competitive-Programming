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
 
ll fat(ll n){
	ll ans = 1;
	for(ll i = 2; i <= n; i++){
		ans = (ans*i%mod)%mod;
	}
	return ans;
}
 
ll modpow(ll x, ll p){
	if(p == 0) return 1;
	ll ans = modpow(x, p/2);
	ans = (ans*ans)%mod;
	if(p&1) return (ans*x%mod)%mod;
	return ans;
}
 
int main(){
	fastio;
	//memset(dp, -1, sizeof dp);
	string s;
	cin >> s;
	int n = len(s);
	ll f = fat(n*1LL);
	map<char, int> freq;
	for(int i = 0; i < n; i++){
		freq[s[i]]++;
	}
	for(auto it = freq.begin(); it != freq.end(); it++){
		f = (f*modpow(fat(it->second), mod-2))%mod;
	}
	cout << f << '\n';
	return 0;
}