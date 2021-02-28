#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
//#define int long long
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
 
const int N = 2505;
 
vector<int> adj[N], ans;
int n, m, vis[N], p[N];
 
int32_t main(){
  //fastio;
  scanf("%d %d", &n, &m);
  vector<tuple<int, int, int>> edges;
  for(int i = 0; i < m; i++){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    adj[a].pb(b);
    edges.emplace_back(a, b, c);
  }
  vector<ll> dist(n+1, LINF);
  for(int i = 0; i < n-1; i++){
    for(auto e : edges){
      int a, b, w;
      tie(a, b, w) = e;
      if(dist[b] > dist[a] + 1LL*w){
        dist[b] = dist[a] + 1LL*w;
        p[b] = a;
      }
    }
  }
  auto ant = dist;
  for(auto e : edges){
    int a, b, w;
    tie(a, b, w) = e;
    if(dist[b] > dist[a] + 1LL*w){
      dist[b] = dist[a] + 1LL*w;
      p[b] = a;
    }
  }
  for(int i = 1; i <= n; i++){
    if(ant[i] != dist[i]){
      puts("YES");
      int v = i;
      while(!vis[v]){
        ans.pb(v);
        vis[v] = 1;
        v = p[v];
      }
      reverse(all(ans));
      while(ans.back() != v) ans.pop_back();
      reverse(all(ans));
      ans.pb(v);
      reverse(all(ans));
      for(int x : ans) printf("%d ", x);
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}