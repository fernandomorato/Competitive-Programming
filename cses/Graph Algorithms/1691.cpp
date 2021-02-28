#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5+5;
 
vector<pair<int, int>> adj[N];
vector<int> path;
int deg[N], used[N], cnt, n, m;
 
inline bool check(){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(deg[i]&1){
			cnt++;
		}
	}
	return cnt == 0;
}
 
void find_path(int v){
	vector<int> stk;
	stk.push_back(v);
	while(!stk.empty()){
		int x = stk.back();
		while(!adj[x].empty() and used[adj[x].back().second]){
			deg[x]--;
			adj[x].pop_back();
		}
		if(!deg[x]){
			path.push_back(x);
			stk.pop_back();
			continue;
		}
		auto v = adj[x].back();
		adj[x].pop_back();
		deg[x]--;
		used[v.second] = 1;
		stk.push_back(v.first);
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back({b, i});
		adj[b].push_back({a, i});
		deg[a]++;
		deg[b]++;
	}
	if(!check()){
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	find_path(1);
	for(int i = 1; i <= m; i++){
		if(!used[i]){
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	for(int x : path){
		cout << x << ' ';
	}
	cout << '\n';
	return 0;
}