#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5+5;
typedef long long ll;
ll arr[N];
 
int main(){
    ll n, ans = 0;
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++){
        scanf("%lld", &arr[i]);
        if(i > 0){
            if(arr[i] < arr[i-1]){
                ans += arr[i-1] - arr[i];
                arr[i] = arr[i-1];
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}