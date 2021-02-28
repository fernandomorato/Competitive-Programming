#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	set<string> st;
	do{
		st.insert(s);
	}while(next_permutation(s.begin(), s.end()));		
	cout << (int)st.size() << '\n';
	while(!st.empty()){
		cout << *st.begin() << '\n';
		st.erase(st.begin());
	}
	return 0;
}