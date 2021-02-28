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
 
int32_t main(){
  fastio;
  int n;
  ll x;
  cin >> n >> x;
  vector<ll> v(n+1), pref(n+1, 0LL);
  for(int i = 1; i <= n; i++){
    cin >> v[i];
    pref[i] = pref[i-1] + v[i];
  }
  int ans = 0;
  for(int i = 1; i <= n; i++){
    int l = i;
    int r = n+1;
    while(l <= r){
      int m = (l+r)>>1;
      if(pref[m]-pref[i-1] == x){
        ans++; 
        break;
      }else if(pref[m]-pref[i-1] < x) l = m+1;
      else r = m-1;
    }
  }
  cout << ans << endl;
  return 0;
}