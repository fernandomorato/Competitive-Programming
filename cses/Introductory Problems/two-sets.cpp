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
const int MOD = 1e9+7;
 
/// command for char arrays with spaces -> scanf(" %[^\n]", text);
 
////////////////////////// Solution starts below. //////////////////////////////
 
int main(){
 
	fastio;
	ll n;
	cin >> n;
	ll sum = n*(n+1);
	if(sum%4 != 0){
		cout << "NO" << '\n';
	}else{
		cout << "YES" << '\n';
		vector<ll> f, s;
		sum /= 4;
		if(sum%n == 0){
		    ll aux = n;
		    f.pb(n);
		    ll l = 1, r = n-1;
		    while(l < r){
		    	if(aux == sum){
		    	    s.pb(l);
		    	    s.pb(r);
		    	    l++, r--;
		    	}else{
		    		aux += (l+r);
		    		f.pb(l);
		    		f.pb(r);
		    		l++, r--;
		    	}
		    }
		}else{
			ll aux = 0;
			ll l = 1, r = n;
			while(l < r){
				if(aux == sum){
					s.pb(l);
					s.pb(r);
					l++, r--;
				}else{
					aux += (l+r);
					f.pb(l);
					f.pb(r);
					l++, r--;
				}
			}
			if(n%2 != 0) s.pb(l);
		}
		cout << len(f) << '\n';
		for(int x : f) cout << x << ' ';
		cout << '\n';
		cout << len(s) << '\n';
		for(int x : s) cout << x << ' ';
		cout << '\n';
	}
	
	return 0;
}