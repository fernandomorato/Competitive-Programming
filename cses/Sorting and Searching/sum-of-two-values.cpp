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
 
    int n, x;
    cin >> n >> x;
    vector<pii> v(n);
    map<pii, int> id;
    for(int i = 0; i < n; i++){
    	int k;
    	cin >> k;
    	v[i] = {k, i};
    	id[v[i]] = i;
    }
	sort(v.begin(), v.end());
	int l = 0, r = n-1;
	while(l < r){
		int sum = v[l].fs + v[r].fs;
		if(sum == x){
			cout << id[v[l]]+1 << ' ' << id[v[r]]+1 << '\n';
			return 0;
		}else if(sum < x) l++;
		else r--;
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}