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
 
typedef vector<vector<ll>> matriz;
 
matriz mult(matriz a, matriz b){
  matriz c(2, vector<ll>(2, 0));
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      for(int z = 0; z < 2; z++){
        c[i][j] = (c[i][j] + (a[i][z]*b[z][j])%MOD)%MOD;
      }
    }
  }
  return c;
}
 
matriz expo2(matriz a, ll p){
  if(p == 1LL) return a;
  matriz k = expo2(a, p/2LL);
  k = mult(k, k);
  if(p&1LL) k = mult(k, a);
  return k;
}
 
int32_t main(){
  fastio;
  ll n;
  cin >> n;
  if(n == 0 or n == 1){
    cout << n << endl;
    return 0;
  }
  matriz m = {{1, 1}, {1, 0}};
  m = expo2(m, n-1);
  cout << (m[0][0])%MOD << endl;
  return 0;
}