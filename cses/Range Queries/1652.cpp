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
 
const int N = 1e3+5;
int m[N][N], pref[N][N];
 
int main(){
 
	char str[N];
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i = 0; i < n; i++){
		scanf("%s", str);
		for(int j = 0; j < n; j++){
			if(str[j] == '*'){
				m[i][j] = 1;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			pref[i][j] = pref[i-1][j] + pref[i][j-1] + m[i-1][j-1] - pref[i-1][j-1];
		}
	}
 
	int _x1, _y1, _x2, _y2;
	while(q--){
		scanf("%d %d %d %d", &_x1, &_y1, &_x2, &_y2);
		int sum = pref[_x2][_y2] - pref[_x1-1][_y2] - pref[_x2][_y1-1] + pref[_x1-1][_y1-1];
		printf("%d\n", sum);
	}
 
	
	return 0;
}