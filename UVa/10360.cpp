#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define LL long long
#define pb push_back

using namespace std;

int grid[2000][2000];
int mark[2000][2000], passo=0;

int main() {
	int T, d, n, x, y, res, count, gustavo, stor;
	scanf("%d", &T);
	while (T--) {
		passo++;
		scanf("%d%d", &d, &n);
		res = 0;
		while (n--) {
			scanf("%d%d%d", &x, &y, &count);
			fr(i,max(x-d,0),x+d+1) {
				fr(j,max(y-d,0),y+d+1) {
					if (mark[i][j]!=passo) mark[i][j]=passo, grid[i][j]=0;
					grid[i][j]+=count;
					if (grid[i][j] > res) {
						res = grid[i][j];
						gustavo = i;
						stor = j;
					}
				}
			}
		}
		printf("%d %d %d\n", gustavo, stor, res);
	}
}