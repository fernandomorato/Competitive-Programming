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
vector<pair<int, ll>> adj[N];
vector<ll> ans;
int n, m, k;
int vis[N];
 
void dijkstra(){
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.push({0, 1});
  while(!pq.empty()){
    int v = pq.top().sc;
    ll w = pq.top().fs;
    pq.pop();
    if(vis[v] == k) continue;
    vis[v]++;
    if(v == n){
      ans.pb(w);
    }
    for(auto e : adj[v]){
      pq.push({e.sc + w, e.fs}); 
    }
  }
}
 
int32_t main(){
  //fastio;
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < m; i++){
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    adj[a].pb({b, w});
  }
  dijkstra();
  sort(all(ans));
  for(int i = 0; i < k; i++){
    printf("%lld ", ans[i]); 
  }
  return 0;
}