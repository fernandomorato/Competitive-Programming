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
 
const int MAXN = 4e5+5;
int entrada[MAXN], saida[MAXN];
map<int, int> valor;
set<int> tempo;
 
// comprimir valores de entrada e saida, mapear os valores e contar as ocorrencias 
 
int main(){
 
	int n;
	scanf("%d", &n);
	vector<pii> v(n);
	for(auto& x : v){
		scanf("%d %d", &x.fs, &x.sc);
		tempo.insert(x.fs);
		tempo.insert(x.sc);
	}
	int cnt = 1;
	for(auto x : tempo){
		valor[x] = cnt++;
	}
	for(int i = 1; i <= n; i++){
		entrada[valor[v[i-1].fs]] = i;
		saida[valor[v[i-1].sc]] = i;
	}
	int active = 0, ans = 0;
	for(int i = 1; i <= cnt; i++){
		if(entrada[i]){
			active++;
		}
		if(saida[i]){
			active--;
		}
		ans = max(ans, active);
	}
	printf("%d\n", ans);
 
	return 0;
}