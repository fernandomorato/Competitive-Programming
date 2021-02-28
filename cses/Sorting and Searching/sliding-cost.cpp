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
int bit[N];  // quantidade
ll bit2[N]; // soma
ll v[N], recu[N];
map<ll, int> id;
 
void updt_sum(int pos, ll valor){
  while(pos <= n){
    bit2[pos] += valor;
    pos += (pos & -pos);
  }
}
 
void updt_quant(int pos, int valor){
  while(pos <= n){
    bit[pos] += valor;
    pos += (pos & -pos);
  }
}
 
ll sum(int pos){
  ll ret = 0LL;
  while(pos){
    ret += bit2[pos];
    pos -= (pos & -pos);
  }
  return ret;
}
 
int quant(int pos){
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
    if(quant(m) >= value) r = m;
    else l = m+1;
  }
  return r;
}
 
inline void add(ll x){
  updt_quant(id[x], 1);
  updt_sum(id[x], x);
}
 
inline void rem(ll x){
  updt_quant(id[x], -1);
  updt_sum(id[x], -x);
}
 
int32_t main(){
  fastio;
  cin >> n >> k;
  for(int i = 1; i <= n; i++){
    cin >> v[i];
    id[v[i]];
  }
  int cnt = 0;
  for(auto it = id.begin(); it != id.end(); it++){
    it->sc = ++cnt;
    recu[cnt] = it->fs;
  }
  for(int i = 1; i < k; i++){
    add(v[i]);
  }
  int meio = (k+1)>>1;
  for(int i = k; i <= n; i++){
    add(v[i]);
    int idxM = get_median(meio);
    ll menor = abs(quant(idxM-1)*recu[idxM] - sum(idxM-1));
    ll maior = abs((quant(n)-quant(idxM))*recu[idxM] - (sum(n) - sum(idxM)));
    cout << menor + maior << ' ';
    rem(v[i-k+1]);
  }
  cout << endl;
  return 0;
}