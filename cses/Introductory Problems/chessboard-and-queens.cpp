#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
char board[10][10];
ll ans;
int i, j;
int col[20], diag1[20], diag2[20];
 
void solve(int j){
	if(j == 8){
		ans++;
	}else{
		for(int i = 0; i < 8; i++){
			if(board[i][j] == '*' or col[i] or diag1[i+j] or diag2[i-j+8-1]) continue;
			col[i] = diag1[i+j] = diag2[i-j+8-1] = 1;
			solve(j+1);
			col[i] = diag1[i+j] = diag2[i-j+8-1] = 0;
		}
	}
}
 
int main(){
	for(int i = 0; i < 8; i++){
		scanf("%s", board[i]);
	}		
	solve(0);
	printf("%lld\n", ans);
	return 0;
}