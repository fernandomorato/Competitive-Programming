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
 
map<int, int> id;
int bit[N], recu[N], v[N];
int n, k;
 
void updt(int pos, int value){
  while(pos <= n){
    bit[pos] += value;
    pos += (pos & -pos);
  }
}
 
int sum(int pos){
  int ret = 0;
  while(pos){
    ret += bit[pos];
    pos -= (pos & -pos);
  }
  return ret;
}
 
int get_median(int value){
  int l = 1, r = n;
  while(l < r){
    int m = (l+r)>>1;
    if(sum(m) >= value) r = m;
    else l = m+1;
  }
  return recu[l];
}
 
int32_t main(){
  fastio;
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    cin >> v[i];
    id[v[i]];
  }
  int cnt = 0;
  for(auto it = id.begin(); it != id.end(); it++){
    it->sc = ++cnt;
    recu[cnt] = it->fs;
  }
  for(int i = 0; i < k-1; i++){
    updt(id[v[i]], 1);
  }
  int c = (k+1)>>1;
  for(int i = k-1; i < n; i++){
    updt(id[v[i]], 1);
    cout << get_median(c) << ' ';
    updt(id[v[i-k+1]], -1);
  }
  cout << endl;
  return 0;
}