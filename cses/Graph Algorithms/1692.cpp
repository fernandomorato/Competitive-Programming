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
 
const int N = 17;
 
map<pii, int> id;
vector<pii> adj[1<<N];
vector<int> lista, tour;
int used[1<<N], out[1<<N], in[1<<N];
 
inline void find(int v){
  vector<int> stk;
  stk.pb(v);
  while(!stk.empty()){
    int x = stk.back();
    while(len(adj[x]) and used[id[adj[x].back()]]){
      out[x]--;
      in[adj[x].back().fs]--;
      adj[x].pop_back();
    }
    if(!out[x]){
      tour.pb(x);
      stk.pop_back();
      continue;
    }
    auto p = adj[x].back();
    adj[x].pop_back();
    out[x]--;
    in[p.fs]--;
    used[id[p]] = 1;
    stk.pb(p.fs);
  }
}
 
int main(){
  fastio;
  int n;
  cin >> n;
  int limit = (1<<n), cnt = 0;
  for(int i = 0; i < limit; i++){
    int v = (i<<1);
    int u = ((i<<1)|1);
    if(v >= limit) v -= limit;
    if(u >= limit) u -= limit;
    adj[i].pb({v, 0});
    adj[i].pb({u, 1});
    id[{v, 0}] = ++cnt;
    id[{u, 1}] = ++cnt;
    out[i] += 2;
    in[v]++;
    in[u]++;
  }
  find(0);
  string ans = "";
  for(int i = 0; i < n-1; i++) ans += '0';
  reverse(all(tour));
  tour.pop_back();
  for(int x : tour){
    if(x&1) ans += '1';
    else ans += '0';
  }
  cout << ans << endl;
  return 0; 
}