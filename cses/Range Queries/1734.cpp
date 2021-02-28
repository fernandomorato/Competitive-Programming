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
const int S = 448;
 
int freq[N];
 
struct Query{
  int l, r, idx;
};
 
bool cmp(Query a, Query b){
  int ax = a.l/S;
  int bx = b.l/S;
  if(ax == bx){
    return a.r < b.r;
  }
  return ax < bx;
}
 
int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> v(n), aux, ans(m);
  for(int i = 0; i < n; i++){
    cin >> v[i];
    aux.pb(v[i]);
  }
  sort(all(aux));
  for(int i = 0; i < n; i++){
    v[i] = lower_bound(all(aux), v[i]) - aux.begin() + 1;
  }
  vector<Query> q(m);
  for(int i = 0; i < m; i++){
    cin >> q[i].l >> q[i].r;
    q[i].l--, q[i].r--;
    q[i].idx = i;
  }
  sort(all(q), cmp);
  int l = 0, r = -1, cnt = 0;
  for(int i = 0; i < m; i++){
    int ql = q[i].l, qr = q[i].r;
    while(l > ql){
      l--;
      freq[v[l]]++;
      if(freq[v[l]] == 1) cnt++;
    }
    while(r < qr){
      r++;
      freq[v[r]]++;
      if(freq[v[r]] == 1) cnt++;
    }
    while(l < ql){
      freq[v[l]]--;
      if(freq[v[l]] == 0) cnt--;
      l++;
    }
    while(r > qr){
      freq[v[r]]--;
      if(freq[v[r]] == 0) cnt--;
      r--;
    }
    ans[q[i].idx] = cnt;
  }
  for(int i = 0; i < m; i++){
    cout << ans[i] << '\n';
  }
  return 0; 
}