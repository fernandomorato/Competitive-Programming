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
 
const int N = 1005;
char grid[N][N];
int dist[2][N][N];
pii ant[N][N];
int n, m;
int vx[] = {-1, 1, 0, 0};
int vy[] = {0, 0, -1, 1};
 
bool isValid(int x, int y){
  return (x >= 0 and x < n and y >= 0 and y < m and grid[x][y] == '.');
}
 
int main(){
  fastio;
  cin >> n >> m;
  queue<pii> q1, q2;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> grid[i][j];
      if(grid[i][j] == 'A'){
        dist[1][i][j] = 0;
        dist[0][i][j] = INF<int>;
        q2.push({i, j});
        ant[i][j] = {i, j};
      }else if(grid[i][j] == 'M'){
        dist[1][i][j] = INF<int>;
        dist[0][i][j] = 0;
        q1.push({i, j});
      }else{
        dist[0][i][j] = dist[1][i][j] = INF<int>;
      }
    }
  }
  // primeira bfs (monstros)
  while(!q1.empty()){
    int x = q1.front().fs;
    int y = q1.front().sc;
    q1.pop();
    for(int i = 0; i < 4; i++){
      int nx = x+vx[i];
      int ny = y+vy[i];
      if(isValid(nx, ny) and dist[0][nx][ny] == INF<int>){
        dist[0][nx][ny] = dist[0][x][y]+1;
        q1.push({nx, ny});
      }
    }
  }
  // segunda bfs (carinha)
  while(!q2.empty()){
    int x = q2.front().fs;
    int y = q2.front().sc;
    q2.pop();
    for(int i = 0; i < 4; i++){
      int nx = x+vx[i];
      int ny = y+vy[i];
      if(isValid(nx, ny) and dist[1][nx][ny] == INF<int>){
        ant[nx][ny] = {x, y};
        dist[1][nx][ny] = dist[1][x][y]+1;
        q2.push({nx, ny});
      }
    }
  }
  int a = -1, b = -1;
  for(int i = 0; i < n; i++){
    if((grid[i][0] == '.' or grid[i][0] == 'A') and dist[0][i][0] > dist[1][i][0]){
      a = i, b = 0;
      break;
    }
    if((grid[i][m-1] == '.' or grid[i][m-1] == 'A') and dist[0][i][m-1] > dist[1][i][m-1]){
      a = i, b = m-1;
      break;
    }
  }
  if(a == -1){
    for(int i = 0; i < m; i++){
      if((grid[0][i] == '.' or grid[0][i] == 'A') and dist[0][0][i] > dist[1][0][i]){
       a = 0, b = i;
       break;
     }
     if((grid[n-1][i] == '.' or grid[n-1][i] == 'A') and dist[0][n-1][i] > dist[1][n-1][i]){
       a = n-1, b = i;
       break;
     }
    }
  }
  if(a == -1 or b == -1){
    cout << "NO\n";
  }else{
    cout << "YES\n";
    vector<char> path;
    while(true){
      pii p = ant[a][b];
      if(p.fs == a-1){
        path.pb('D');
      }else if(p.fs == a+1){
        path.pb('U');
      }else if(p.sc == b-1){
        path.pb('R');
      }else if(p.sc == b+1){
        path.pb('L');
      }else break;
      a = p.fs;
      b = p.sc;
    }
    reverse(all(path));
    cout << len(path) << endl;
    for(char ch : path){
      cout << ch;
    }
    cout << endl;
  }
  return 0;
}