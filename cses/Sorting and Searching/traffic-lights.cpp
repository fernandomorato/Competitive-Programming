#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
#define fs first
#define sc second
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define len(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> pll;
 
template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
template<typename T>
inline T mod(T n, T mod){ T res = n%mod; if(res < 0) res += mod; return res; }
 
/// command for char arrays with spaces -> scanf(" %[^\n]", text);
 
////////////////////////// Solution starts below. //////////////////////////////
 
int main(){
  fastio;
  int x, n;
  cin >> x >> n;
  set<int> caras;
  set<pii> gaps;
  set<pair<int, pii>> st;
  caras.insert(0);
  caras.insert(x);
  gaps.insert({0, x});
  st.insert({-x, {0, x}});
  for(int i = 0; i < n; i++){
    int k;
    cin >> k;
    auto l = caras.lower_bound(k);
    auto r = caras.upper_bound(k);
    l--;
    gaps.erase({*l, *r});
    caras.insert(k);
    while(!st.empty() and !gaps.count(st.begin()->sc)){
      st.erase(st.begin());
    }
    st.insert({*l-k, {*l, k}});
    st.insert({k-*r, {k, *r}});
    gaps.insert({*l, k});
    gaps.insert({k, *r});
    cout << -st.begin()->fs << ' ';
  }
  cout << endl;
  return 0;
}