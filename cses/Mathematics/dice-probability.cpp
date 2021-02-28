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
 
int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  vector<vector<double>> p(n+1, vector<double>(6*n+1, 0));
  for(int i = 1; i <= 6; i++){
    p[1][i] = 1.0/6.0;
  }
  for(int i = 2; i <= n; i++){
    for(int j = 1; j <= b; j++){
      for(int k = 1; k <= 6; k++){
        if(k > j) break;
        p[i][j] += (p[i-1][j-k] * p[1][k]);
      }
    }
  }
  double ans = 0;
  for(int i = a; i <= b; i++){
    ans += p[n][i];
  }
  cout << setprecision(6) << fixed << ans << '\n';
  return 0; 
}