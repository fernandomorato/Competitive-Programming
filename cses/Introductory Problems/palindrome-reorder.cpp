#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	map<char, int> freq;
	int n = (int)s.size();
	for(int i = 0; i < n; i++){
		freq[s[i]]++;
	}	
	int cnt = 0, freqCarinha = 0;
	string a = "", b = "";
	char carinha = '*';
	for(auto it = freq.begin(); it != freq.end(); it++){
		if(it->second%2 == 1){
			cnt++;
			if(cnt == 2){
				cout << "NO SOLUTION\n";
				return 0;
			}
			carinha = it->first;
			freqCarinha = it->second;
			continue;
		}
		for(int i = 0; i < it->second/2; i++){
			a += it->first;
			b += it->first;
		}
	}
	if(carinha != '*'){
		for(int i = 0; i < freqCarinha; i++){
			a += carinha;
		}
	}
	reverse(b.begin(), b.end());
	cout << a+b << endl;
	return 0;
}