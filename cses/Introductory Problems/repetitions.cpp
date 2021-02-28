#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;
    int maior = 1, cnt = 1;
    int n = str.length();
    for(int i = 1; i <= n; i++){
        if(i < n){
            if(str[i-1] == str[i]){
                cnt++;
                maior = max(maior, cnt);
            }else{
                cnt = 1;
            }
        }
    }
    printf("%d\n", maior);
}