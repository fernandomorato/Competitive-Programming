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
 
////////////////////////// Solution starts below. //////////////////////////////
 
int n;
int bit[1005][1005];
 
void update(int x, int y, int value){
  for(int i = x; i <= n; i += (i & -i)){
    for(int j = y; j <= n; j += (j & -j)){
      bit[i][j] += value;
    }
  }
}
 
int sum(int x, int y){
  int ret = 0;
  for(int i = x; i > 0; i -= (i & (-i))){
    for(int j = y; j > 0; j -= (j & (-j))){
      ret += bit[i][j];
    }
  }
  return ret;
}
 
int get(int x1, int y1, int x2, int y2){
  return sum(x2, y2) - sum(x2, y1-1) - sum(x1-1, y2) + sum(x1-1, y1-1);
}
 
int main(){
  fastio;
  int q;
  cin >> n >> q;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      char ch;
      cin >> ch;
      if(ch == '*'){
        update(i, j, 1);
      }
    }
  }
  while(q--){
    int tipo;
    cin >> tipo;
    if(tipo&1){
      int x, y;
      cin >> x >> y;
      if(get(x, y, x, y)) update(x, y, -1);
      else update(x, y, 1);
    }else{
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      cout << get(x1, y1, x2, y2) << endl;
    }
  }
  return 0;
}