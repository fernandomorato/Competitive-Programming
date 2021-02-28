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
 
const int N = 1e5+5;
int n, m;
vector<pair<int, ll>> adj[N];
bitset<N> vis[2];
 
ll dijkstra(){
  vector<ll> dist(n+1, INF<ll>);
  set<pair<ll, pii>> st;
  st.insert({0, {1, 0}});
  dist[1] = 0;
  while(!st.empty()){
    auto aux = *st.begin();
    st.erase(st.begin());
    ll wgt = aux.fs;
    int v = aux.sc.fs;
    int flag = aux.sc.sc;
    if(v == n){
      dist[n] = wgt;
      break;
    }
    if(vis[flag][v]) continue;
    vis[flag][v] = 1;
    //cout << v << ' ' << dist[v] << ' ' << flag << endl;
    for(auto e : adj[v]){
      int u = e.fs;
      ll w = e.sc;
      st.insert({wgt+w, {u, flag}});
      if(!flag){
        st.insert({wgt+w/2, {u, 1}});
      }
    }
  }
  return dist[n];
}
 
int main(){
  fastio;
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a, b;
    ll c;
    cin >> a >> b >> c;
    adj[a].pb({b, c});
  }
  cout << dijkstra() << endl;
  return 0;
}