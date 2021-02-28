#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
#define fs first
#define sc second
#define pb push_back
#define len(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n); i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpl;
typedef vector<vl> vvl;
 
template<typename T> void maxself(T &a, T &b){a = max(a, b);};
template<typename T> void minself(T &a, T &b){a = min(a, b);};
 
const ll LINF = 1e18;
const int INF = 1e9;
const int MOD = 1e9+7;
 
/// command for char arrays with spaces -> scanf(" %[^\n]", text);
 
////////////////////////// Solution starts below. //////////////////////////////
 
const int N = 2e5+5;
ll v[N], bit[N];
int n, q;
 
void add(int idx, ll value){
	for(; idx <= n; idx += idx&(-idx)){
		bit[idx] += value;
	}
}
 
ll sum(int idx){
	ll ans = 0;
	for(; idx > 0; idx -= idx&(-idx)){
		ans += bit[idx];
	}
	return ans;
}
 
ll sum(int a, int b){
	return sum(b) - sum(a-1);
}
 
int main(){
 
	scanf("%d %d", &n, &q);
	for(int i = 0; i < n; i++){
		scanf("%lld", &v[i]);
		add(i+1, v[i]);
	}
	while(q--){
		int k, a, b;
		scanf("%d %d %d", &k, &a, &b);
		if(k == 1){
			add(a, b-v[a-1]);
			v[a-1] = b;
		}else{
			printf("%lld\n", sum(a, b));
		}
	}
	
	return 0;
}