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
    ll t, x, y;
	cin >> t;
    while(t--){
    	cin >> y >> x;
    	if(x > y){
    		if(x%2){
    			cout << x*x-y+1 << '\n';
    		}else{
    			x--;
    			cout << x*x+y << '\n';
    		}
    	}else{
    		if(y%2 == 0){
    			cout << y*y-x+1 << '\n';
    		}else{
    			y--;
    			cout << y*y+x << '\n';
    		}
    	}
    }
	
	return 0;
}