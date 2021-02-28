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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& x : a) cin >> x;
	vector<int> stk;
	for(int x : a){
		auto it = lower_bound(stk.begin(), stk.end(), x);
		if(it == stk.end()) stk.pb(x);
		else *it = x;
	}
	cout << len(stk) << '\n';
	return 0;
}