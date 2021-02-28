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
 
ll f(ll n){
	return (n*n*(n*n-1) - 8 - 24 - (n-4)*16 - 16 - 24*(n-4) - ((n-4)*(n-4))*8)/2;
} 
 
int main(){
 
	fastio;
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++){
    	cout << f(i) << '\n';
    }
	
	return 0;
}