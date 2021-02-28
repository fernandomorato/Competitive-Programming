#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
//#define int long long
#define endl '\n'
#define fs first
#define sc second
#define pb push_back
#define len(x) ((int)(x).size())     
#define all(x) (x).begin(), (x).end()
#define test int _; cin >> _; while(_--)
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
 
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
 
ll gcd(ll a, ll b){return (b == 0LL ? a : gcd(b, a%b));}
inline ll mod(ll a, ll b){return ((a%b)+b)%b;}
inline ll expo(ll b, ll p, ll m = MOD){
  ll ans = 1; 
  while(p > 0){
    if(p&1LL) ans = mod(ans*b, m); 
    b = mod(b*b, m); 
    p >>= 1LL;
  } 
  return ans;
}
 
////////////////////////// Solution starts below. //////////////////////////////
 
const int N = 1e5+5;
 
int p[N], rnk[N], sz[N];
 
int find(int v){
  return (v == p[v] ? v : p[v] = find(p[v]));
}
 
int merge(int v, int u){
  int x = find(v);
  int y = find(u);
  if(x != y){
    if(rnk[x] > rnk[y]) swap(x, y);
    p[x] = y;
    sz[y] += sz[x];
    if(rnk[x] == rnk[y]) rnk[y]++;
    return 1;
  }
  return 0;
}
 
int32_t main(){
  fastio;
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    p[i] = i;
    rnk[i] = 0;
    sz[i] = 1;
  }
  int maior = 0, comps = n;
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    if(merge(a, b)) comps--;
    maior = max(maior, sz[find(a)]);
    cout << comps << ' ' << maior << endl;
  }
  return 0;
}