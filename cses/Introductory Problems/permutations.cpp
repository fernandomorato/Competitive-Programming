#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
#define fs first
#define sc second
#define pb push_back
#define len(x) ((int)(x).size())
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
 
const ll LINF = 1e18;
const int INF = 1e9;
const int MOD = 1e9+7;
 
/// command for char arrays with spaces -> scanf(" %[^\n]", text);
 
////////////////////////// Solution starts below. //////////////////////////////
 
int main(){
 
	int n;
	scanf("%d", &n);
	vector<int> ans;
	for(int i = 1; i <= n; i++){
		if(i%2 == 0) ans.push_back(i);
	}
	for(int i = 1; i <= n; i++){
		if(i%2) ans.push_back(i);
	}
	for(int i = 1; i < n; i++){
		if(abs(ans[i] - ans[i-1]) == 1){
			puts("NO SOLUTION");
			return 0;
		}
	}
	for(int x : ans) printf("%d ", x);
	putchar('\n');
	return 0;
}