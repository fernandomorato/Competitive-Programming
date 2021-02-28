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
 
const int N = 1e6+5;
 
ll fat[N], inv[N];
 
void setup(int n){
  fat[0] = inv[0] = 1LL;
  for(int i = 1; i < N; i++){
    fat[i] = (i*fat[i-1])%MOD;
  }
  inv[N-1] = expo(fat[N-1], MOD-2);
  for(int i = N-2; i > 0; i--){
    inv[i] = (inv[i+1] * (i+1))%MOD;
  }
}
 
int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  setup(n);
  ll sum = 0;
  for(int i = 2; i <= n; i++){
    if(i&1) sum = mod(sum - inv[i], MOD);
    else sum = mod(sum + inv[i], MOD);
  }
  cout << mod(fat[n]*sum, MOD) << '\n';
  return 0; 
}