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
 
int main(){
	fastio;
	string a, b;
	cin >> a >> b;
	int A = len(a), B = len(b);
	vector<vector<int>> dp(A+1, vector<int>(B+1, 0));
	for(int i = 1; i <= A; i++){
		dp[i][0] = i;
	}
	for(int j = 1; j <= B; j++){
		dp[0][j] = j;
	}
	for(int i = 1; i <= A; i++){
		for(int j = 1; j <= B; j++){
			if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]})+1;
		}
	} 
	cout << dp[A][B] << endl;
	return 0;
}