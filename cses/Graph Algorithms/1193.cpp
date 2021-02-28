#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////
 
#define fs first
#define sc second
#define pb push_back
#define len(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n); i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpl;
typedef vector<vl> vvl;
 
template<typename T> void maxself(T &a, T &b){a = max(a, b);};
template<typename T> void minself(T &a, T &b){a = min(a, b);};
 
const ll LINF = 1e18;
const int INF = 1e9;
const int MOD = 1e9+7;
 
/// command for char arrays with spaces -> scanf(" %[^\n]", text);
 
////////////////////////// Solution starts below. //////////////////////////////
 
char grid[1005][1005];
pii ant[1005][1005];
int dist[1005][1005];
int vx[] = {-1, 0, 1, 0};
int vy[] = {0, 1, 0, -1};
int n, m;
 
bool isValid(int i, int j){
	return (i >= 0 and i < n and j >= 0 and j < m);
}
 
pii bfs(int i, int j){
	queue<pii> q;
	q.push({i, j});
	dist[i][j] = 0;
	ant[i][j] = pii(i, j);
	while(!q.empty()){
		int x = q.front().fs;
		int y = q.front().sc;
		q.pop();
		if(grid[x][y] == 'B'){
			grid[x][y] = '#';
			return pii(x, y);
		}
		if(grid[x][y] == '#') continue;
		grid[x][y] = '#';
		forn(k, 4){
			int a = x+vx[k];
			int b = y+vy[k];
			if(isValid(a, b) and grid[a][b] != '#'){
				ant[a][b] = pii(x, y);
				dist[a][b] = dist[x][y] + 1;
				q.push({a, b});
			}
		}
	}
}
 
int main(){
 
	scanf("%d %d", &n, &m);
	forn(i, n){
		scanf("%s", grid[i]);
	}
	bool foi = false;
	pii p;
	forn(i, n){
		forn(j, m){
			if(grid[i][j] == 'A'){
				p = bfs(i, j);
				foi = true;
				break;
			}
			if(foi) break;
		}
	}
	forn(i, n){
		forn(j, m){
			if(grid[i][j] == 'B'){
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	pii aux = ant[p.fs][p.sc];
	printf("%d\n", dist[p.fs][p.sc]);
	stack<char> st;
	while(p != aux){
		forn(i, 4){
			int a = p.fs+vx[i];
			int b = p.sc+vy[i];
			if(a == aux.fs and b == aux.sc){
				if(i == 0) st.push('D');
				else if(i == 1) st.push('L');
				else if(i == 2) st.push('U');
				else st.push('R');
				break;
			}
		}
		swap(p, aux);
		aux = ant[p.fs][p.sc];
	}
	while(!st.empty()){
		printf("%c", st.top());
		st.pop();
	}
	putchar('\n');
	return 0;
}