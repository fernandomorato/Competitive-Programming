#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
//#define int long long
//#define endl '\n'
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
 
int board[8][8];
int vx[] = {2, 2, 1, -1, -2, -2, -1, 1};
int vy[] = {-1, 1, 2, 2, 1, -1, -2, -2};
 
bool valid(int x, int y){
  return (x >= 0 and x < 8 and y >= 0 and y < 8 and !board[x][y]);
}
 
int disp(pii nxt){
  int x = nxt.fs;
  int y = nxt.sc;
  int cnt = 0;
  for(int i = 0; i < 8; i++){
    int nx = x + vx[i];
    int ny = y + vy[i];
    if(valid(nx, ny)) cnt++;
  }
  return cnt;
}
 
void dfs(int x, int y, int mv){
  board[x][y] = mv;
  if(mv == 64){
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        cout << board[i][j] << ' ';
      }
      cout << '\n';
    }
    exit(0);
  }
  vector<pii> moves;
  for(int i = 0; i < 8; i++){
    int nx = x+vx[i];
    int ny = y+vy[i];
    if(valid(nx, ny)) moves.pb({nx, ny});
  }
  sort(all(moves), [&](pii& a, pii& b){
    return disp(a) < disp(b);
  });
  for(pii nxt : moves){
    dfs(nxt.fs, nxt.sc, mv+1);
  }
  board[x][y] = 0;
}
 
int main(){
  fastio;
  int a, b;
  cin >> a >> b;
  dfs(b-1, a-1, 1);
  return 0; 
}