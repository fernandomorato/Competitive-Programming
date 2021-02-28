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
 
matrix id(7, vector<ll>(7, 0));
 
matrix mult(matrix a, matrix b){
  matrix resu(7, vector<ll>(7));
  for(int i = 0; i < 7; i++){
    for(int j = 0; j < 7; j++){
      for(int k = 0; k < 7; k++){
        resu[i][j] = mod(resu[i][j]%MOD + mod(a[i][k] * b[k][j], MOD), MOD);
      }
    }
  }
  return resu;
}
 
matrix expo(matrix m, ll p){
  if(!p) return id;
  matrix a = expo(m, p/2);
  a = mult(a, a);
  if(p&1) a = mult(a, m);
  return a;
}
 
int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  matrix a(7, vector<ll>(7, 0));
  a[0][0] = 1;
  matrix m(7, vector<ll>(7));
  m[0][0] = 1, m[0][1] = 1;
  m[1][0] = 1, m[1][2] = 1;
  m[2][0] = 1, m[2][3] = 1;
  m[3][0] = 1, m[3][4] = 1;
  m[4][0] = 1, m[4][5] = 1;
  m[5][0] = 1, m[5][6] = 1;
  for(int i = 0; i < 7; i++){
    id[i][i] = 1;
  }
  m = expo(m, n);
  a = mult(m, a);
  cout << a[0][0] << '\n';
  return 0; 
}