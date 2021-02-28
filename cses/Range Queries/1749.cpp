#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
#define fs first
#define sc second
#define pb push_back
#define len(x) ((int)(x).size())
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef tree<pii,null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
const ll LINF = 1e18;
const int INF = 1e9;
const int MOD = 1e9+7;
 
/// command for char arrays with spaces -> scanf(" %[^\n]", text);
 
////////////////////////// Solution starts below. //////////////////////////////
 
 
int main(){
 
	indexed_set v;
	int n, x;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		v.insert({i, x});
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		x--;
		pii a = *v.find_by_order(x);
		printf("%d ", a.sc);
		v.erase(v.find_by_order(x));
	}
	putchar('\n');
}