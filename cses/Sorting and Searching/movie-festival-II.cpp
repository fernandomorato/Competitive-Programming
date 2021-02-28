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
  int n, k;
  cin >> n >> k;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  multiset<int> st;
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    pq.emplace(b, a);
  }
  int ans = 0;
  st.insert(0);
  while(!pq.empty()){
    int start = pq.top().sc;
    int end = pq.top().fs;
    pq.pop();
    auto it = st.upper_bound(start);
    if(it == st.begin()){
      if(len(st) < k){
        st.insert(end);
        ans++;
      }
    }else{
      it--;
      st.erase(it);
      st.insert(end);
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}