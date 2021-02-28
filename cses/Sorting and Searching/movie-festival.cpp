#include <bits/stdc++.h>
using namespace std;
 
bool func(const pair<int, int> a, const pair<int, int> b){
	return a.second < b.second;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(auto& p : v){
		cin >> p.first >> p.second;
	}
	stack<pair<int, int> > st;
	sort(v.begin(), v.end(), func);
	for(auto p : v){
		if(st.empty()) st.push(p);
		else{
			if(p.first >= st.top().second){
				st.push(p);
			}
		}
	}
	cout << st.size() << '\n';
	return 0;
}