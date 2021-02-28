#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
#define fs first
#define sc second
#define pb push_back
//#define int long long
#define len(x) (int)(x).size()     
#define all(x) (x).begin(), (x).end()
#define test int _; cin >> _; while(_--)
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
 
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
 
inline ll gcd(ll a, ll b){while(b){ a %= b; swap(a, b); } return a; }
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
 
typedef vector<vector<ll>> matrix;
 
int n;
 
matrix mult(matrix a, matrix b){
  matrix resu(n, vector<ll>(n));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k < n; k++){
        resu[i][j] = mod(resu[i][j]%MOD + mod(a[i][k] * b[k][j], MOD), MOD);
      }
    }
  }
  return resu;
}
 
matrix expo(matrix m, ll p){
  if(p == 1) return m;
  matrix a = expo(m, p/2);
  a = mult(a, a);
  if(p&1) a = mult(a, m);
  return a;
}
 
int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, k;
  cin >> n >> m >> k;
  matrix adj(n, vector<ll>(n, 0));
  vector<int> v(n);
  v[0] = 1;
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    adj[b-1][a-1]++;
  }
  adj = expo(adj, k);
  ll ans = 0;
  for(int i = 0; i < n; i++){
    ans = (ans + mod(adj[n-1][i] * v[i], MOD))%MOD;
  }
  cout << ans << '\n';
  return 0; 
}