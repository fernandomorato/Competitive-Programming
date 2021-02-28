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
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
const ll linf = 1e18;
const int inf = 1e9;
const int mod = 1e9+7;
 
/// command for char arrays with spaces -> scanf(" %[^\n]", text);
 
////////////////////////// Solution starts below. //////////////////////////////
 
const int N = 2e5+5;
int v[N];
 
int main(){
 
	fastio;
	int n, q;
	cin >> n >> q;
	indexed_set st;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		st.insert(v[i]);
	}
	char c;
	int a, b;
	while(q--){
		cin >> c >> a >> b;
		if(c == '?'){
			cout << st.order_of_key(b+1) - (int)st.order_of_key(a) << endl;
		}else{
			a--;
			st.erase(st.find_by_order(st.order_of_key(v[a])));
			v[a] = b;
			st.insert(b);
		}
	}
	
	return 0;
}