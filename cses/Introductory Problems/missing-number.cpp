#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5;
bitset<N> vis;
 
int main(){
    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        vis[x] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}