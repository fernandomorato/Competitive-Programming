#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int l = 0, r = 0, maior = 0;
	set<int> st;
	while(r < n){
		while(st.count(v[r])){
			st.erase(st.find(v[l]));
			l++;
		}
		st.insert(v[r]);
		r++;
		maior = max(maior, (int)st.size());
	}
	cout << maior << '\n';
	return 0;
} 