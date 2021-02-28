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
vector<pii> adj[N];
int out[N], in[N], used[N], n, m;
vector<int> tour;
 
bool check(){
  for(int i = 2; i < n; i++){
    if(in[i] != out[i]) return false;
  }
  return true;
}
 
void find(int v){
  vector<int> stk;
  stk.pb(v);
  while(!stk.empty()){
    int x = stk.back();
    //stk.pop_back();
    while(adj[x].size() and used[adj[x].back().sc]){
      in[adj[x].back().fs]--;
      out[x]--;
      adj[x].pop_back();
    }
    if(!out[x]){
      tour.pb(x);
      stk.pop_back();
      continue;
    }
    auto p = adj[x].back();
    adj[x].pop_back();
    in[p.fs]--, out[x]--;
    used[p.sc] = 1;
    stk.pb(p.fs);
  }
}
 
int main(){
  fastio;
  cin >> n >> m;
  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;
    adj[a].pb({b, i});
    out[a]++, in[b]++;
  }
  if(!check() or (out[1]-in[1] != 1) or (in[n]-out[n] != 1)){
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  find(1);
  for(int i = 1; i <= m; i++){
    if(!used[i]){
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }
  reverse(all(tour));
  for(int x : tour) cout << x << ' ';
  cout << '\n';
  return 0; 
}