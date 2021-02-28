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
 
const int N = 2e5+5;
 
int anc[20][N];
 
int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for(int i = 2; i <= n; i++){
    cin >> anc[0][i];
  }
  for(int d = 1; d < 20; d++){
    for(int v = 1; v <= n; v++){
      anc[d][v] = anc[d-1][anc[d-1][v]];
    }
  }
  while(q--){
    int x, k;
    cin >> x >> k;
    for(int d = 19; d >= 0; d--){
      if(k&(1<<d)) x = anc[d][x];
    }
    if(!x) x = -1;
    cout << x << '\n';
  }
  return 0; 
}