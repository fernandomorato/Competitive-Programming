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
const ll MOD = 1e9+7;
 
/// command for char arrays with spaces -> scanf(" %[^\n]", text);
 
////////////////////////// Solution starts below. //////////////////////////////
 
ll sqr(ll x){ return x*x; }
 
ll pot2(ll n){
	if(n == 1) return 2LL;
	if(n%2 == 0) return sqr(pot2(n/2))%MOD;
	return 2LL*pot2(n-1)%MOD;
}
 
int main(){
 
    ll n;
    cin >> n;
    cout << pot2(n)%MOD << '\n';
	
	return 0;
}