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
 
const int N = 2e5+5;
int n, a, b;
ll v[N], pref[N];
 
int32_t main(){
  scanf("%d%d%d", &n, &a, &b);
  for(int i = 1; i <= n; i++){
    scanf("%lld", &v[i]);
    pref[i] = pref[i-1] + v[i];
  }
  multiset<ll> st;
  ll ans = -1e18;
  for(int i = 0; i <= n; i++){
    if(i >= a) st.insert(pref[i-a]);
    if(!st.empty()){
      ans = max(ans, pref[i] - (*st.begin()));
    }
    if(i >= b){
      auto it = st.find(pref[i-b]);
      st.erase(it);
    }
  }
  printf("%lld\n", ans);
  return 0;
}