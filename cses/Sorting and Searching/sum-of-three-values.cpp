#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
#define int long long
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
 
const int N = 5005;
int v[N];
 
int32_t main(){
  fastio;
  int n, x;
  cin >> n >> x;
  vector<pii> aux;
  for(int i = 0; i < n; i++){
    cin >> v[i];
    aux.emplace_back(v[i], i);
  }
  sort(all(aux));
  bool found = false;
  for(int i = 0; i < n-2; i++){
    int sum = x-aux[i].fs;
    int l = i+1, r = n-1;
    while(l < r and !found){
      if(aux[l].fs + aux[r].fs == sum){
        found = true;
        cout << aux[i].sc+1 << ' ' << aux[l].sc+1 << ' ' << aux[r].sc+1 << endl;
        break;
      }else if(aux[l].fs + aux[r].fs < sum) l++;
      else r--;
    }
    if(found) break;
  }
  if(!found) cout << "IMPOSSIBLE\n";
  return 0;
}