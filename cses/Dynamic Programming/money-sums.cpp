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
 
int main(){
	fastio;
	int n, maxx = 0;
	cin >> n;
	vector<int> c(n);
	for(int i = 0; i < n; i++){
		cin >> c[i];
		maxx += c[i];
	}
	vector<int> foi(maxx+5, 0);
	foi[0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = maxx; j >= c[i]; j--){
			foi[j] |= foi[j-c[i]];
		}
	}
	vector<int> v;
	for(int i = 1; i <= maxx; i++){
		if(foi[i]) v.pb(i);
	}
	cout << len(v) << '\n';
	for(int x : v) cout << x << ' ';
	cout << '\n';
	return 0;
}