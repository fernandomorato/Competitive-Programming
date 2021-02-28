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
 
bool vis[7][7];
string s;
int ans;
 
bool valid(int i, int j){
  return (i >= 0 and i < 7 and j >= 0 and j < 7 and !vis[i][j]);
}
 
void dfs(int i, int j, int ptr = 0){
  if(i == 6 and j == 0){
    if(ptr == 48) ans++;
    return;
  }
  if((i == 0 or i == 6)){
    if(valid(i, j-1) and valid(i, j+1)) return;
  }
  if((j == 0 or j == 6)){
    if(valid(i-1, j) and valid(i+1, j)) return;
  }
 
  vis[i][j] = true;
  if(s[ptr] == '?' or s[ptr] == 'L'){
    if(valid(i, j-1) and !(!valid(i, j-2) and valid(i-1, j-1) and valid(i+1, j-1))){
      dfs(i, j-1, ptr+1);
    }
  }
  if(s[ptr] == '?' or s[ptr] == 'U'){
    if(valid(i-1, j) and !(!valid(i-2, j) and valid(i-1, j-1) and valid(i-1, j+1))){
      dfs(i-1, j, ptr+1);
    }
  }
  if(s[ptr] == '?' or s[ptr] == 'R'){
    if(valid(i, j+1) and !(!valid(i, j+2) and valid(i-1, j+1) and valid(i+1, j+1))){
      dfs(i, j+1, ptr+1);
    }
  }
  if(s[ptr] == '?' or s[ptr] == 'D'){
    if(valid(i+1, j) and !(!valid(i+2, j) and valid(i+1, j-1) and valid(i+1, j+1))){
      dfs(i+1, j, ptr+1);
    }
  }
  vis[i][j] = false;
}
 
int32_t main(){
  fastio;
  cin >> s;
  dfs(0, 0);
  cout << ans << endl;
  return 0;
}