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
 
typedef long double ld;
 
int vx[] = {0, 0, 1, -1};
int vy[] = {-1, 1, 0, 0};
 
bool valid(int x, int y){
  return (x >= 0 and x < 8 and y >= 0 and y < 8);
}
 
bool esquina(int x, int y){
  if(x == 0 or x == 7) return (y == 0 or y == 7);
  return false;
}
 
bool canto(int x, int y){
  if(x == 0 or x == 7) return (y > 0 and y < 7);
  if(y == 0 or y == 7) return (x > 0 and x < 7);
  return false;
}
 
ld dp[64][105][8][8], grid[8][8];
 
int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m;
  cin >> m;
  int cnt = 0;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      dp[cnt++][0][i][j] = 1.0;
    }
  }
  for(int k = 1; k <= m; k++){
    for(int robot = 0; robot < 64; robot++){
      for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
          for(int l = 0; l < 4; l++){
            int nx = vx[l]+i;
            int ny = vy[l]+j;
            if(!valid(nx, ny)) continue;
            if(esquina(nx, ny)){
              dp[robot][k][i][j] += dp[robot][k-1][nx][ny]/2.0;
            }else if(canto(nx, ny)){
              dp[robot][k][i][j] += dp[robot][k-1][nx][ny]/3.0;
            }else{
              dp[robot][k][i][j] += dp[robot][k-1][nx][ny]/4.0;
            }
          }
        }
      }
    }
  }
  for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        grid[i][j] = 1.0;
      }
    }
  ld ans = 0;
  for(int robot = 0; robot < 64; robot++){
    for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
        grid[i][j] *= (1.0-dp[robot][m][i][j]);
      }
    }
  }
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      ans += grid[i][j];
    }
  }
  cout << setprecision(6) << fixed << ans << '\n';
  return 0; 
}