#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
ll p[25];
vector<ll> v;
ll total, diff;
int n;
 
void search(int i){
	if(i == n){
		ll sum = 0;
		for(ll x : v){
			sum += x;
		}
		if(sum != total){
			diff = min(diff, abs(total-2*sum));
		}	
	}else{
		v.push_back(p[i]);
		search(i+1);
		v.pop_back();
		search(i+1);
	}	
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> p[i];
		total += p[i];
	}
	diff = total;
	search(0);
	cout << diff << endl;
	return 0;
}