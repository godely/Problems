#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long
#define MAXN 111
using namespace std;

int grid[111][111];
bool mark[111];
int p[]={0,1,0,-1};
int q[]={1,0,-1,0};
int n;

bool pode(int i, int j) { return (i>=0&&i<n&&j>=0&&j<n); }
int ff(int i, int j) {
	int c = grid[i][j];
	grid[i][j]=-1;
	int ret = 1;
	rp(k,4) if (pode(i+p[k],j+q[k]) && grid[i+p[k]][j+q[k]]==c) ret+=ff(i+p[k],j+q[k]);
	return ret;
}

char gbn[1111];
char gb[11111];
char *r;
int size;
int main() {
	int a, b;
	while (gets(gbn) && gbn[0]!='0') {
		n = atoi(gbn);
		memset(grid,0,sizeof grid);
		bool ok = 1;
		fr(i,1,n) {
			gets(gb);
			if (!(r=strtok(gb," "))) continue;
			a = atoi(r);
			r=strtok(NULL, " ");
			b = atoi(r);
			grid[a-1][b-1]=i;
			while ((r=strtok(NULL, " "))) {
				a = atoi(r);
				r = strtok(NULL, " ");
				b = atoi(r);
				grid[a-1][b-1]=i;
			}
		}
		memset(mark,0,sizeof mark);
		for (int i = 0; i < n && ok; i++) {
			rp(j,n) {
				if (grid[i][j]==-1) continue;
				if (!mark[grid[i][j]]) {
					if (ff(i,j)!=n) {
						ok=0;
						break;
					}
					mark[grid[i][j]]=1;
				} else {
					ok=0;
					break;
				}
			}
		}
		if (ok) printf("good\n");
		else printf("wrong\n");
	}
	return 0;
}