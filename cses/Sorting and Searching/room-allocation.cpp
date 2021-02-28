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
 
map<pair<int, pii>, int> room;
 
int main(){
  fastio;
  int n;
  cin >> n;
  vector<pair<int, pii>> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i].fs >> a[i].sc.fs;
    a[i].sc.sc = i;
  }
  vector<pair<int, pii>> v = a;
  int quant = 0;
  sort(all(v));
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  for(int i = 0; i < n; i++){
    if(pq.empty()){
      room[v[i]] = 1;
      pq.push({v[i].sc.fs, room[v[i]]});
    }else{
      if(pq.top().fs < v[i].fs){
        room[v[i]] = pq.top().sc;
        pq.pop();
        pq.push({v[i].sc.fs, room[v[i]]});
      }else{
        room[v[i]] = len(pq) + 1;
        pq.push({v[i].sc.fs, room[v[i]]});
      }
    }
    quant = max(quant, room[v[i]]);
  }
  cout << quant << '\n';
  for(auto e : a){
    cout << room[e] << ' ';
  }
  cout << '\n';
  return 0;
}