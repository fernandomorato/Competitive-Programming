#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
#define fs first
#define sc second
#define endl '\n'
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
 
int main(){
  int n;
  scanf("%d", &n);
  while(n--){
    int x, ans = 0;
    scanf("%d", &x);
    for(int i = 1; i*i <= x; i++){
      if(x%i == 0){
        ans++;
        if(i*i != x) ans++;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}