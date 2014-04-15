#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long
#define MAXN 111
using namespace std;

char grid[111][111];
int p[]={0,1,0,-1};
int q[]={1,0,-1,0};
int n,m;
char land;

bool pode(int i, int j) { return (i>=0&&i<m && grid[i][(j+n)%n] == land); }
int ff(int i, int j) {
	int ret=1;
	grid[i][j]=0;
	rp(k,4) if (pode(i+p[k],j+q[k])) ret+=ff(i+p[k],(j+q[k]+n)%n);
	return ret;
}

int main() {
	int x, y;
	while (scanf("%d%d", &m, &n)==2) {
		rp(i,m) scanf("%s", grid[i]);
		int maximo=0;
		scanf("%d%d", &x, &y);
		land = grid[x][y];
		ff(x,y);
		rp(i,n) rp(j,n) if (pode(i,j)) maximo=max(maximo,ff(i,j));
		printf("%d\n", maximo);
	}
	return 0;
}