#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long
#define MAXN 1000010
#define inf 0x3f3f3f3f

using namespace std;

char control[111111];
char grid[111][111];
int p[]={-1,0,1,0};
int q[]={0,1,0,-1};
int N, M, D;
int f(char c) {
	return (c=='N') ? 0 : (c=='L') ? 1 : (c=='S') ? 2 : 3;
}
bool pode(int i, int j) {
	return (i>=0 && i < N && j >= 0 && j < M && grid[i][j] != '#');
}

int main() {
	int x, y, k, count;
	bool found;
	while (scanf("%d%d%d", &N, &M, &D) == 3 && N > 0) {
		found = 0;
		rp(i,N) {
			scanf("%s", grid[i]);
			if (!found) {
				rp(j,N) {
					if (grid[i][j]>='A' && grid[i][j]<='Z') {
						x = i, y = j, k = f(grid[i][j]);
						found=1;
						break;
					}
				}
			}
		}
		scanf("%s", control);
		count = 0;
		grid[x][y]='.';
		rp(i,D) {
			if (control[i]=='E') k=(k+3)%4;
			else if (control[i]=='D') k=(k+1)%4;
			else {
				if (pode(x+p[k],y+q[k])) {
					x+=p[k], y+=q[k];
					count+=(grid[x][y]=='*');
					grid[x][y]='.';
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}