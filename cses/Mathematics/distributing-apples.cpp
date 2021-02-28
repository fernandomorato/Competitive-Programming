#include <bits/stdc++.h>
using namespace std;
 
const long long int MOD = 1e9+7;
 
int expo(int b, int p){
  if(p == 0) return 1;
  if(p == 1) return b;
  int u = expo(b, p>>1);
  u = (1LL*u*u)%MOD;
  if(p&1) u = (1LL*u*b)%MOD;
  return u;
}
 
int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  int fat = 1;
  for(int i = n+m-1; i > 0; i--){
    fat = (1LL * fat * i)%MOD;
  }
  int fatm = 1;
  for(int i = m; i > 0; i--){
    fatm = (1LL * fatm * i)%MOD;
  }
  int fatn = 1;
  for(int i = n-1; i > 0; i--){
    fatn = (1LL * fatn * i)%MOD;
  }
  printf("%lld\n", ((1LL * fat * expo(fatm, MOD-2))%MOD * 1LL * expo(fatn, MOD-2))%MOD);
  return 0;
}