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
 
int n, k;
ll v[N];
 
bool check(ll value){
  ll sum = 0;
  int divisions = 0;
  for(int i = 0; i < n; i++){
    if(v[i] > value) return false;
    sum += v[i];
    if(sum > value){
      sum = v[i];
      divisions++;
    }
    if(divisions >= k) return false;
  }
  return true;
}
 
int32_t main(){
  fastio;
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  ll l = 0, r = 2e14+5, best = 0;
  while(l <= r){
    ll m = (l+r)>>1;
    if(check(m)){
      best = m;
      r = m-1;
    }else{
      l = m+1;
    }
  }
  cout << best << endl;
  return 0;
}