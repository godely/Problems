#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long
#define MAXN 111
using namespace std;

char grid[111][111];
int p[]={0,1,0,-1};
int q[]={1,0,-1,0};
int n;

bool pode(int i, int j) { return (i>=0&&i<n&&j>=0&&j<n && grid[i][j]!='.'); }
int ff(int i, int j) {
	int ret=(grid[i][j]=='x');
	grid[i][j]='.';
	rp(k,4) if (pode(i+p[k],j+q[k])) ret|=ff(i+p[k],j+q[k]);
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	fr(cas,1,T+1){
		scanf("%d", &n);
		rp(i,n) scanf("%s", grid[i]);
		int count=0;
		rp(i,n)rp(j,n) if(pode(i,j)) count+=ff(i,j);
		printf("Case %d: %d\n", cas, count);
	}
	return 0;
}