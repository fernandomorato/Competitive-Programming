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
 
const int N = 1e5;
int p[N], rnk[N];
 
int find(int v){
	if(p[v] == v) return v;
	return p[v] = find(p[v]);
}
 
void merge(int v, int u){
	int x = find(v);
	int y = find(u);
	if(x != y){
		if(rnk[x] > rnk[y]) swap(x, y);
		p[x] = y;
		if(rnk[x] == rnk[y]) rnk[y]++;
	}
}
 
int main(){
 
	int n, m;
	scanf("%d %d", &n, &m);
	for1(i, n) p[i] = i;
	int a, b;
	forn(i, m){
		scanf("%d %d", &a, &b);
		merge(a, b);
	}
	set<int> st;
	for1(i, n) st.insert(find(i));
	printf("%d\n", len(st)-1);
	while(!st.empty()){
		int x = *st.begin();
		st.erase(st.begin());
		if(st.empty()) break;
		int y = *st.begin();
		st.erase(st.begin());
		merge(x, y);
		printf("%d %d\n", x, y);
		st.insert(find(x));
	}
	return 0;
}