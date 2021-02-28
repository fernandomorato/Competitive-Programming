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
const ll MOD = (ll)1e9 + 7;
 
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
  ll n, ans = 0;
  cin >> n;
  ll inv2 = expo(2, MOD-2)%MOD;
  for(ll l = 1, r; l <= n; l = r+1){
    ll aux = n/l;
    r = n / (n/l); // todo i em [l, r] tem mesmo n/i
    ll sumR = (mod(mod(r, MOD) * mod(r+1, MOD), MOD) * inv2)%MOD;
    ll sumL = (mod(mod(l, MOD) * mod(l-1, MOD), MOD) * inv2)%MOD;
    ll total = mod(sumR-sumL, MOD);
    ans = mod(mod(ans, MOD) + mod(mod(total, MOD) * mod(aux, MOD), MOD), MOD);
  }
  cout << ans << '\n';
  return 0; 
}