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
 
const int N = 1e5+5;
map<pii, int> ans;
 
int32_t main(){
  fastio;
  int n;
  cin >> n;
  vector<int> v(n);
  vector<pii> aux;
  set<int> st;
  for(int i = 0; i < n; i++){
    cin >> v[i];
    aux.emplace_back(v[i], i);
  }
  sort(all(aux));
  for(int i = 0; i < n; i++){
    pii p = aux[i];
    auto it = st.lower_bound(p.sc);
    if(st.empty()) ans[p] = -1;
    else{
      if(it == st.begin()){
        ans[p] = -1;
        st.insert(p.sc);
        continue;
      }
      it--;
      bool flag = false;
      while(v[*it] == p.fs){
        if(it == st.begin()){
          flag = true;
          if(v[*it] < p.fs){
            ans[p] = *it;
          }
          else ans[p] = -1;
          break;
        }
        it--;
      }
      if(!flag) ans[p] = *it;
    }
    st.insert(p.sc);
  }
  cout << endl;
  for(int i = 0; i < n; i++){
    cout << ans[{v[i], i}]+1 << ' ';
  }
  cout << endl;
  return 0;
}