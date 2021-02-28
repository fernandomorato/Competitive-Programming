#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	ll pot = 5;
	ll ans = n/pot;
	for(int i = 2; i <= 12; i++){
		pot *= 5;
		ans += n/pot;
	}
	cout << ans << '\n';
	return 0;
}