/**
 *    author:  morato
 *    created: 19.08.2020 13:13:44
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  long long sum = 0;
  map<long long, long long> mp;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
    mp[sum]++;
  }
  sum = 0;
  long long ans = mp[k];
  for (int i = 0; i < n; i++) {
    sum += v[i];
    mp[sum]--;
    ans += mp[k + sum];
  }
  cout << ans << '\n';
  return 0;
}