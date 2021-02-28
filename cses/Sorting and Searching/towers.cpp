#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n), towers;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		auto it = upper_bound(towers.begin(), towers.end(), v[i]);
		if(it == towers.end()) towers.push_back(v[i]);
		else *it = v[i];
	}
	cout << towers.size() << '\n';
	return 0;
} 