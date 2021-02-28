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
  int n, x;
  cin >> n >> x;
  vector<pii> v(n+1);
  for(int i = 1; i <= n; i++){
    cin >> v[i].fs;
    v[i].sc = i;
  }
  sort(all(v));
  bool flag = false;
  for(int i = 1; i <= n; i++){
    for(int j = i+3; j <= n; j++){
      int l = i+1;
      int r = j-1;
      while(l < r){
        int sum = v[i].fs + v[l].fs + v[r].fs + v[j].fs;
        if(sum == x){
          cout << v[i].sc << ' ' << v[l].sc << ' ' << v[r].sc << ' ' << v[j].sc << endl;
          flag = true;
          break;
        }else if(sum < x) l++;
        else r--;
      }
      if(flag) break;
    }
    if(flag) break;
  }
  if(!flag) cout << "IMPOSSIBLE\n";
  return 0;
}